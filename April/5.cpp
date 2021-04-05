class Solution
{
public:
    int mergeSort(vector<int> &arr, vector<int> &temp, int l, int r)
    {
        int inv_count = 0;
        if (l < r)
        {
            int mid = (l + r) / 2;
            inv_count += mergeSort(arr, temp,
                                   l, mid);
            inv_count += mergeSort(arr, temp,
                                   mid + 1, r);

            inv_count += merge(arr, temp, l,
                               mid + 1, r);
        }
        return inv_count;
    }
    int merge(vector<int> &arr, vector<int> &temp, int l, int m, int r)
    {
        int i = l, j = m;
        int k = l;
        int inv_count = 0;
        while (i <= (m - 1) && j <= r)
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                inv_count += (m - i);
            }
        }
        while (i <= (m - 1))
        {
            temp[k++] = arr[i++];
        }
        while (j <= r)
        {
            temp[k++] = arr[j++];
        }
        int p = 0;
        for (int i = l; i <= r; i++)
        {
            arr[i] = temp[i];
        }
        return inv_count;
    }
    int mergesort(vector<int> &arr)
    {
        vector<int> temp(arr.size());
        return mergeSort(arr, temp, 0, arr.size() - 1);
    }
    bool isIdealPermutation(vector<int> &A)
    {
        int local_inv = 0;
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (A[i + 1] < A[i])
                local_inv++;
        }
        int inv_count = mergesort(A);
        cout << inv_count << endl;
        if (local_inv == inv_count)
            return true;
        return false;
    }
};