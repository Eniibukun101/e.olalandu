#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int load_data(const char filename[], int ids[], int scores[], int max_size);
void print_all(int ids[], int scores[], int size);
void compute_stats(int scores[], int size, double &average, int &min_score, int &max_score);
void compute_grade_distribution(int scores[], int size,
                                int &count_a, int &count_b, int &count_c,
                                int &count_d, int &count_f);
int pick_random_passing_student(int ids[], int scores[], int size);
void save_summary(const char filename[],
                  double average, int min_score, int max_score,
                  int count_a, int count_b, int count_c,
                  int count_d, int count_f);

int main() {

    const int MAX_SIZE = 100;
    int ids[MAX_SIZE];
    int scores[MAX_SIZE];

    int size = load_data("scores.csv", ids, scores, MAX_SIZE);

    cout << "Total number of students: " << size << endl << endl;

    print_all(ids, scores, size);

    double average = 0;
    int min_score = 0;
    int max_score = 0;

    compute_stats(scores, size, average, min_score, max_score);

    cout << "\nAverage score: " << average << endl;
    cout << "Minimum score: " << min_score << endl;
    cout << "Maximum score: " << max_score << endl;

    int count_a = 0, count_b = 0, count_c = 0, count_d = 0, count_f = 0;

    compute_grade_distribution(scores, size,
                               count_a, count_b, count_c,
                               count_d, count_f);

    cout << "\nGrade Distribution:\n";
    cout << "A: " << count_a << endl;
    cout << "B: " << count_b << endl;
    cout << "C: " << count_c << endl;
    cout << "D: " << count_d << endl;
    cout << "F: " << count_f << endl;

    srand(time(0));

    int index = pick_random_passing_student(ids, scores, size);

    if (index == -1) {
        cout << "\nNo passing student found.\n";
    } else {
        cout << "\nRandom passing student selected:\n";
        cout << "StudentID: " << ids[index] << "  Score: " << scores[index] << endl;
    }

    save_summary("summary.csv", average, min_score, max_score,
                 count_a, count_b, count_c, count_d, count_f);

    cout << "\nsummary.csv has been created.\n";

    return 0;
}

int load_data(const char filename[], int ids[], int scores[], int max_size) {

    ifstream file(filename);

    if (!file) {
        cout << "Could not open file\n";
        return 0;
    }

    string header;
    getline(file, header); // ignore first line

    int count = 0;
    char comma;

    while (count < max_size && file >> ids[count] >> comma >> scores[count]) {
        count++;
    }

    file.close();
    return count;
}

void print_all(int ids[], int scores[], int size) {

    for (int i = 0; i < size; i++) {
        cout << "StudentID: " << ids[i] << "   Score: " << scores[i] << endl;
    }
}

void compute_stats(int scores[], int size, double &average, int &min_score, int &max_score) {

    int sum = 0;

    min_score = scores[0];
    max_score = scores[0];

    for (int i = 0; i < size; i++) {

        sum += scores[i];

        if (scores[i] < min_score) {
            min_score = scores[i];
        }

        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }

    average = (double) sum / size;
}

void compute_grade_distribution(int scores[], int size,
                                int &count_a, int &count_b, int &count_c,
                                int &count_d, int &count_f) {

    for (int i = 0; i < size; i++) {

        int sc = scores[i];

        if (sc >= 70) count_a++;
        else if (sc >= 60) count_b++;
        else if (sc >= 50) count_c++;
        else if (sc >= 45) count_d++;
        else count_f++;
    }
}

int pick_random_passing_student(int ids[], int scores[], int size) {

    int passing_indexes[100];
    int pass_count = 0;

    for (int i = 0; i < size; i++) {

        if (scores[i] >= 50) {
            passing_indexes[pass_count] = i;
            pass_count++;
        }
    }

    if (pass_count == 0) {
        return -1;
    }

    int r = rand() % pass_count;
    return passing_indexes[r];
}

void save_summary(const char filename[],
                  double average, int min_score, int max_score,
                  int count_a, int count_b, int count_c,
                  int count_d, int count_f) {

    ofstream file(filename);

    file << "Metric,Value\n";
    file << "Number of Students," << (count_a + count_b + count_c + count_d + count_f) << "\n";
    file << "Average Score," << average << "\n";
    file << "Minimum Score," << min_score << "\n";
    file << "Maximum Score," << max_score << "\n";
    file << "A Count," << count_a << "\n";
    file << "B Count," << count_b << "\n";
    file << "C Count," << count_c << "\n";
    file << "D Count," << count_d << "\n";
    file << "F Count," << count_f << "\n";

    file.close();
}
