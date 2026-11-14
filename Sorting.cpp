#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) {
            cout << " ";
        }
    }
}
//Selection Sort by swaping
void selectionSort(vector<int>& arr) {
    int step = 0;
    int n = (int)arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minimumIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minimumIndex]) {
                minimumIndex = j;
            }
        }

        if (minimumIndex != i) {
            int firstValue = arr[i];
            int secondValue = arr[minimumIndex];

            swap(arr[i], arr[minimumIndex]);

            step++;
            cout << "Step " << step << ": Swap " << firstValue
                 << " and " << secondValue << " -> ";
            printVector(arr);
            cout << "\n";
        }
    }

    cout << "Sorted: ";
    printVector(arr);
    cout << "\n";
}

//Bubble Sort swapping adjacent in right order then move the pass
void bubbleSort(vector<int>& arr) {
    int step = 0;
    int n = (int)arr.size();

    for (int pass = 1; pass < n; pass++) {
        bool swapped = false;

        for (int j = 0; j < n - pass; j++) {
            if (arr[j] > arr[j + 1]) {
                int firstValue = arr[j];
                int secondValue = arr[j + 1];

                swap(arr[j], arr[j + 1]);

                step++;
                cout << "Pass " << pass << ", Step " << step
                     << ": Swap " << firstValue << " and " << secondValue
                     << " -> ";
                printVector(arr);
                cout << "\n";

                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    cout << "Sorted: ";
    printVector(arr);
    cout << "\n";
}

//Insertion Sort insert unsorted to the sorted side
void insertionSort(vector<int>& arr) {
    int step = 0;
    int n = (int)arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        step++;
        cout << "Step " << step << ": Insert " << key << " -> ";
        printVector(arr);
        cout << "\n";
    }

    cout << "Sorted: ";
    printVector(arr);
    cout << "\n";
}

//Merge the splitted array
void merge(vector<int>& arr, int low, int middle, int high, int depth) {
    vector<int> leftHalf(arr.begin() + low, arr.begin() + middle + 1);
    vector<int> rightHalf(arr.begin() + middle + 1, arr.begin() + high + 1);

    int leftIndex = 0;
    int rightIndex = 0;
    int mergedIndex = low;

    while (leftIndex < (int)leftHalf.size() && rightIndex < (int)rightHalf.size()) {
        if (leftHalf[leftIndex] <= rightHalf[rightIndex]) {
            arr[mergedIndex] = leftHalf[leftIndex];
            leftIndex++;
        } else {
            arr[mergedIndex] = rightHalf[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    while (leftIndex < (int)leftHalf.size()) {
        arr[mergedIndex] = leftHalf[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    while (rightIndex < (int)rightHalf.size()) {
        arr[mergedIndex] = rightHalf[rightIndex];
        rightIndex++;
        mergedIndex++;
    }

    for (int i = 0; i < depth; i++) {
        cout << "    ";
    }

    cout << "Merge: [";
    for (int i = 0; i < (int)leftHalf.size(); i++) {
        cout << leftHalf[i];
        if (i < (int)leftHalf.size() - 1) cout << " ";
    }
    cout << "] + [";
    for (int i = 0; i < (int)rightHalf.size(); i++) {
        cout << rightHalf[i];
        if (i < (int)rightHalf.size() - 1) cout << " ";
    }
    cout << "] -> [";
    for (int i = low; i <= high; i++) {
        cout << arr[i];
        if (i < high) cout << " ";
    }
    cout << "]\n";
}
//Merge Sort calls merge() 
void mergeSort(vector<int>& arr, int low, int high, int depth) {
    if (low >= high) {
        return;
    }

    int middle = low + (high - low) / 2;

    for (int i = 0; i < depth; i++) {
        cout << "    ";
    }

    cout << "Split: [";
    for (int i = low; i <= high; i++) {
        cout << arr[i];
        if (i < high) {
			cout << " ";
		}
    }
    cout << "] -> [";
    for (int i = low; i <= middle; i++) {
        cout << arr[i];
        if (i < middle) {
			cout << " ";
		}
    }
    cout << "] | [";
    for (int i = middle + 1; i <= high; i++) {
        cout << arr[i];
        if (i < high) {
			cout << " ";
		}
    }
    cout << "]\n";

    mergeSort(arr, low, middle, depth + 1);
    mergeSort(arr, middle + 1, high, depth + 1);

    merge(arr, low, middle, high, depth);
}

int main() {
    int size;

    do {
        cout << "Enter number of elements (1-10): ";
        cin >> size;
        if (size < 1 || size > 10) {
            cout << "Invalid. Please enter 1 to 10.\n";
        }
    } while (size < 1 || size > 10);

    vector<int> original(size);

    for (int i = 0; i < size; i++) {
    	cout << "Enter element " << (i + 1) << ": ";
        cin >> original[i];
    }

    cout << "\nOriginal array: ";
    printVector(original);
    cout << "\n\n";

    cout << "Selection Sort\n";
    vector<int> selection = original;
    cout << "Start: ";
    printVector(selection);
    cout << "\n";
    selectionSort(selection);

    cout << "\n";

    cout << "Bubble Sort\n";
    vector<int> bubble = original;
    cout << "Start: ";
    printVector(bubble);
    cout << "\n";
    bubbleSort(bubble);

    cout << "\n";

    cout << "Insertion Sort\n";
    vector<int> insertion = original;
    cout << "Start: ";
    printVector(insertion);
    cout << "\n";
    insertionSort(insertion);

    cout << "\n";

    vector<int> merge = original;
    cout << "Merge Sort\nStart: ";
    printVector(merge);
    cout << "\n";
    mergeSort(merge, 0, size - 1, 0);
    cout << "Sorted: ";
    printVector(merge);
    cout << "\n";

    return 0;
}
