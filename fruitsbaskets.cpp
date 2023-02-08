class Solution {
public:

    // returns the maximum number of fruits that can be picked given a starting position
    int findMaxAtStartingPos(vector<int>& fruits, int start) {
        int fruit1 = -1;
        int fruit2 = -1;
        int count = 0;

        // Set tree1Type to the type of tree at the starting position, and add one to that tree's count
        fruit1 = fruits[start];
        count++;


        for (int i = start + 1; i < fruits.size(); i++) {
            if (fruits[i] == fruit1 || fruits[i] == fruit2) {
                count++;
            }
            else if (fruit2 == -1) {
                fruit2 = fruits[i];
                count++;
            }
            else // we have found a third type of tree. exit the loop
                break;
        }

        return count;

    }

    int totalFruit(vector<int>& fruits) {
        if (fruits.size() == 0)
            return 0;
        if (fruits.size() == 1)
            return 1;
        if (fruits.size() == 2)
            return 2;
        int maxFruit = 0;

        int j = 0;

        // if maxFruit is above this value, no point in checking further values
        int majority = (fruits.size() / 2) + 1;

        for (int i = 0; i < fruits.size() - 2; i++) {
            maxFruit = max(maxFruit, findMaxAtStartingPos(fruits, i));
            if (maxFruit >= majority)
                break;
        }


        return maxFruit;
    }
};