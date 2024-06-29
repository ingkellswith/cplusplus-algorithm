#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function for computing the maximum length of a common subsequence between two sequences and finding the LCS itself
pair<string, int> find_longest_common_subsequence(const string& X, const string& Y);
// Function for finding the most similar sequence of a given sequence
void find_most_similar_sequences(const vector<string>& sequences, ofstream& output_file);
// Function for printing the LCS and its length
void store_result(ofstream& output_file, int max_index, int max_length, const string& max_lcs, bool is_last);

int main(int argc, char *argv[]) {
    // Input stream
    ifstream input_file(argv[1]);
    // Output stream
    ofstream output_file(argv[2]);

    // Error handling
    if (!input_file.is_open() || !output_file.is_open()) {
        cout << "Cannot open the file" << endl;
        return 1;
    }

    // Getting sequence length
    int n;
    input_file >> n;
    // Remove the newline character
    input_file.ignore();

    // Read input_file and store each line in string variable 'line'
    string line;
    vector<string> sequences;
    while (getline(input_file, line)) {
        sequences.push_back(line);
    }

    // Finding the most similar sequence of a given sequence
    find_most_similar_sequences(sequences, output_file);

    // Resource deallocation
    input_file.close();
    output_file.close();

    return 0;
}

// Function for computing the maximum length of a common subsequence between two sequences and finding the LCS itself
pair<string, int> find_longest_common_subsequence(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();

    // Initialize a table to store the length of LCS between prefixes of X and Y
    // c[i][j] represents the length of LCS between X[0..i-1] and Y[0..j-1]
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    // Calculate the length of LCS using the bottom-up dynamic programming approach
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    // Trace back the LCS from the table to reconstruct the LCS string
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            // If the characters match, it belongs to the LCS
            // Move diagonally up-left in the table
            lcs = X[i - 1] + lcs;
            --i;
            --j;
        } else if (c[i - 1][j] > c[i][j - 1]) {
            // If the length above is greater, move up in the table
            --i;
        } else {
            // Otherwise, move left in the table
            --j;
        }
    }

    return make_pair(lcs, lcs.length());
}

// Function for finding the most similar sequence of a given sequence
void find_most_similar_sequences(const vector<string>& sequences, ofstream& output_file) {
    // Loop through each sequence in the input file
    for (int i = 0; i < sequences.size(); ++i) {
        int max_length = 0;
        string max_lcs;
        int max_index = -1;
        // Compare the current sequence (sequences[i]) with all other sequences to find 'most similar' sequence
        for (int j = 0; j < sequences.size(); ++j) {
            // Avoid comparing a sequence with itself
            if (i != j) {
                // Find the longest common subsequence (LCS) between the current sequence (sequences[i]) and the other sequence (sequences[j])
                auto result = find_longest_common_subsequence(sequences[i], sequences[j]);
                // Update the information if the LCS found is longer than the previous maximum
                if (result.second > max_length) {
                    max_length = result.second;
                    max_lcs = result.first;
                    max_index = j;
                }
            }
        }
        // Function for printing the LCS and its length
        if(i==(sequences.size()-1)){
            store_result(output_file, max_index, max_length, max_lcs, true);
        } else {
            store_result(output_file, max_index, max_length, max_lcs, false);
        }
    }
}

// Function for printing the LCS and its length
void store_result(ofstream& output_file, int max_index, int max_length, const string& max_lcs, bool is_last) {
    // +1 to max_index considering first line of input.txt
    // Store result at output_file
    if(is_last){
        output_file << max_index + 1 << '\t' << max_length << '\t' << max_lcs;
    }else{
        output_file << max_index + 1 << '\t' << max_length << '\t' << max_lcs << endl;
    }
}