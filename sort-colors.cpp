#include "iostream"
#include "vector"

using namespace std;

void merge(vector<int> nums, int start, int mid, int end)
{
    int start1 = start, end1 = mid, start2 = mid + 1, end2 = end;
    if (nums[end1] <= nums[start2])
        return;

    while (start1 <= end1 && start2 <= end2)
    {
        if (nums[start1] <= nums[start2])
            start1++;
        else
        {
            int value = nums[start2];
            int index = start2;

            while (index != start1)
            {
                nums[index] = nums[index - 1];
                index--;
            }
            nums[start1] = value;

            start1++;
            end1++;
            start2++;
        }
    }
}

void mergeSort(vector<int> &nums, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid, end);
        merge(nums, start, mid, end);
    }
}

void sortColors(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size());
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &ele : vec)
        cin >> ele;
    sortColors(vec);
}