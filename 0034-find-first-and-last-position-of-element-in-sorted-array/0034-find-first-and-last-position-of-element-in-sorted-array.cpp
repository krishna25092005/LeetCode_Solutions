class Solution {
public:
    void firstOccurrence(vector<int>arr, int size, int target,int &firstOccIndex)
{
    int start=0;
    int end=size-1;
    int mid = start + (end-start)/2;
    while(start<=end) {
        if(arr[mid]==target) {
            // ans found but may or may not be first occurrence
            // store and compute
            firstOccIndex=mid;
            // kyoki first occurrence ki bat horri h
            // to btao left me jau ya right me
            end=mid-1;
        }
        else if(target>arr[mid])
        // right me jao
        start=mid+1;
        else 
        // left me jao
        end=mid-1;

        // ye me bhul jata hu
        mid = start + (end-start)/2;
    }
    // agar aap yaha tk phuch gye to
    // iska mtlb poora loop chl chuka hai
    // isla mtlb poore loop me kahi bhi target ni mila
    // iska mtlb element not found
    // iska mtlb return false
   
}
    void lastOccurrence(vector<int>arr, int size, int target,int &lastOccIndex)
{
    int start=0;
    int end=size-1;
    int mid = start + (end-start)/2;
    while(start<=end) {
        if(arr[mid]==target) {
            // ans found but may or may not be first occurrence
            // store and compute
            lastOccIndex=mid;
            // kyoki last occurrence ki bat horri h
            // to btao left me jau ya right me
            // to hum jaege right me
            start=mid+1;
        }
        else if(target>arr[mid])
        // right me jao
        start=mid+1;
        else 
        // left me jao
        end=mid-1;

        // ye me bhul jata hu
        mid = start + (end-start)/2;
    }
    // agar aap yaha tk phuch gye to
    // iska mtlb poora loop chl chuka hai
    // isla mtlb poore loop me kahi bhi target ni mila
    // iska mtlb element not found
    // iska mtlb return false
   
}

    vector<int> searchRange(vector<int>& arr, int target) {
       int n=arr.size();

       int firstOccIndex = -1;
       firstOccurrence(arr,n,target,firstOccIndex);

       int lastOccIndex = -1;
       lastOccurrence(arr,n,target,lastOccIndex);
        
    vector<int>temp(2);
    temp[0]=firstOccIndex;
    temp[1]=lastOccIndex;
    return temp;

    }
};