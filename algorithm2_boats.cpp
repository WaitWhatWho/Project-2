#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minBoatsRequired(vector<int>& people, int limit) {
    sort(people.begin(), people.end());

    int left = 0;
    int right = people.size() - 1;
    int boats = 0;

    while (left <= right) {
        // If the lightest and heaviest can share a boat
        if (people[left] + people[right] <= limit) {
            left++;
            right--;
        } else {
            // Heaviest person goes alone
            right--;
        }
        boats++;
    }

    return boats;
}

int main() {
    int n, limit;

    cout << "Enter number of people: ";
    cin >> n;

    vector<int> people(n);

    cout << "Enter the weights of the people (add a space between each number): ";
    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }

    cout << "Enter boat weight limit: ";
    cin >> limit;

    int result = minBoatsRequired(people, limit);

    cout << "Minimum number of boats required: " << result << endl;

    return 0;
}
