/*
for (count k:n)
{
    length[k]=1;
    for (count int i:k)
    {
        if (array[i]<array[k]){
            length[k]=max(length[k],length[i]+1)
        }
    }
}

for (count k:n)
{
    length[k]=1;

    if array[k]>array[]
}

solve(int x)
{
    for (count k:n)
    {if array[x]>array[k] && x-k>0
    length[x]=max(length[x],solve[x-k]+1)}
}


for (int k = 0; k < n; k++) {
length[k] = 1;
for (int i = 0; i < k; i++) {
if (array[i] < array[k]) {
length[k] = max(length[k],length[i]+1);
}
}



*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> buckets; // the list of buckets
    vector<int> prev(n, -1); // the array of previous indices
    vector<int> index(n); // the array of current indices
    buckets.push_back(nums[0]); // initialize the first bucket
    index[0] = 0; // the index of the first element is 0
    for (int i = 1; i < n; i++) {
        if (nums[i] > buckets.back()) { // if the element is greater than the last bucket
            buckets.push_back(nums[i]); // append it to the end of the list
            prev[i] = index[buckets.size() - 2]; // the previous index of this element is the index of the last bucket before appending
            index[buckets.size() - 1] = i; // the current index of this element is i
        } else { // otherwise
            int low = lower_bound(buckets.begin(), buckets.end(), nums[i]) - buckets.begin(); // find the position to update using binary search
            buckets[low] = nums[i]; // replace the element at that position with the current element
            prev[i] = low > 0 ? index[low - 1] : -1; // the previous index of this element is the index of the previous bucket, or -1 if there is no previous bucket
            index[low] = i; // the current index of this element is i
        }
    }
    // print the actual LIS by tracing back the prev array
    cout << "The longest increasing subsequence is: ";
    int curr = index.back(); // start from the last element
    stack<int> s; // use a stack to reverse the order
    while (curr != -1) { // while there is a previous element
        s.push(nums[curr]); // push the current element to the stack
        curr = prev[curr]; // move to the previous element
    }
    while (!s.empty()) { // while the stack is not empty
        cout << s.top() << " "; // pop and print the element from the stack
        s.pop();
    }
    cout << endl;
    // return the length of the LIS
    return buckets.size();
}

int main() {
    vector<int> nums = {10, 12, 9, 13, 21, 50, 41, 65, 85};
    cout << "The length of the longest increasing subsequence is: " << lengthOfLIS(nums) << endl;
    return 0;
}
