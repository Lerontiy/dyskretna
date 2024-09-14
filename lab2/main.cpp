#include <iostream>
using namespace std;

int sort(int l[]) {
    for (int i=0; i<sizeof(l)/4; i++){
        cout << l[i] << " ";
    }
    int start = 0;
    int buffer, buffer1;

    cout << endl;
    
    do {
        buffer = start;
        for (int i=start; i<sizeof(l)/4; i++){
            if (l[i] < l[buffer]) {
                buffer = i;
            }
        }
        buffer1 = l[buffer];
        l[buffer] = l[start];
        l[start] = buffer1;
        start++;
    } while (start < sizeof(l)/4);

    for (int i=0; i<sizeof(l)/4; i++){
        cout << l[i] << " ";
    }
    
    return 0;
}

int main() {
    int l[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << sort(l);
    return 0;
}