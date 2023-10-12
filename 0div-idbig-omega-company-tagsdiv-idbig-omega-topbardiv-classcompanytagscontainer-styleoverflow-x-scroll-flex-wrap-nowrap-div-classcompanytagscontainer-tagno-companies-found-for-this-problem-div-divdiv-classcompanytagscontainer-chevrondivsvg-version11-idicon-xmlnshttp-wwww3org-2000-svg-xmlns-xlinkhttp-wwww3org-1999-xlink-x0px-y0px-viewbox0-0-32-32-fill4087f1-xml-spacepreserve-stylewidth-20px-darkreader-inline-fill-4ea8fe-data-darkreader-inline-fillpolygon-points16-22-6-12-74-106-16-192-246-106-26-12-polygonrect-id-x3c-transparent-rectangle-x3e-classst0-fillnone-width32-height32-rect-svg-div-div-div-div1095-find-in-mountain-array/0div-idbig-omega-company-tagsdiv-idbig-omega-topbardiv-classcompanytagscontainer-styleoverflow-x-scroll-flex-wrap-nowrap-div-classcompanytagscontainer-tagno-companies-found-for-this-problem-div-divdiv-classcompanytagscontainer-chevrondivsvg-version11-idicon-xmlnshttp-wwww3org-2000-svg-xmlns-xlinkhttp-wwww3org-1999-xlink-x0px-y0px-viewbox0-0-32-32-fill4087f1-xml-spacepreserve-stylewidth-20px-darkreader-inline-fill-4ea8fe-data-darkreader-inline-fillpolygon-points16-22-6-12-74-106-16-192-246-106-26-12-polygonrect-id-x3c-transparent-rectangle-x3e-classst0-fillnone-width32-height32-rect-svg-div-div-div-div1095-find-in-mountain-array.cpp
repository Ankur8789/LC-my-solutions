/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {

        int len = mountainArr.length();
        int pivotIndex = pivotSearch(mountainArr);
        int leftSearch = binarySearch(0, pivotIndex, target, mountainArr, false);
        if (leftSearch != -1)
        {
            return leftSearch;
        }
        return binarySearch(pivotIndex + 1, len - 1, target, mountainArr, true);
    }

    int binarySearch(int s, int e, int target, MountainArray arr, bool rightSearch)
    {
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            int num = arr.get(mid);
            if (num == target)
            {
                return mid;
            }
            if (rightSearch)
            {

                if (num < target)
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            else
            {

                if (num < target)
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }
        return -1;
    }

    int pivotSearch(MountainArray arr)
    {
        int len = arr.length();
        int s = 0;
        int e = len - 1;
        while (s < e)
        {
            int mid = s + (e - s) / 2;
            if (arr.get(mid) < arr.get(mid + 1))
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }
        return s;
    }
};