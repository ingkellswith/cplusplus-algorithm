#include <iostream>
using namespace std;
#include <iomanip>
using std::setw;

void printBubbles(const int bubbles[], const int n);
void lineup(int* large, int* small);  // �Լ� ���� ����

int main()
{
    const int n = 10;
    int bubbles[n] = { 100, 90, 80, 70, 60, 50, 40, 30, 20, 10 };

    cout << "Data items in original order\n";
    printBubbles(bubbles, n);
    for (int level = 0; level < n - 1; level++) {
        for (int i = 0; i < n - level - 1; i++) {
            if (bubbles[i] > bubbles[i + 1])
                lineup(&bubbles[i], &bubbles[i + 1]);  // �����ͷ� �ּ� ����
        }
    }
    cout << "\nData items in ascending order\n";
    printBubbles(bubbles, n);
    return 0;
}

void printBubbles(const int bubbles[], const int n) {
    for (int i = 0; i < n; i++)
        cout << setw(4) << bubbles[i];
    cout << endl;
}

void lineup(int* large, int* small) {  // �����ͷ� ����
    int save = *large;  // ������ �������Ͽ� �� �б�
    *large = *small;    // ������ �������Ͽ� �� ����
    *small = save;      // ������ �������Ͽ� �� ����
}
