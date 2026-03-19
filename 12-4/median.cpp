#include <vector>
#include<iostream>
using namespace std;

    float findMedianSortedArrays(vector <int>&nums1,vector<int> &nums2) {
        // int m=nums1.size();
        // int n=nums2.size();
        vector<int> result;
        int i=0,j=0,k=0;
        while(nums1.size()!=0 && nums2.size()!=0){
            if (nums1[i]>nums2[j]){
                result.push_back(nums2[j]);
                j++;
                k++;
                nums2.size()--;

            }
            else {
                result.push_back(nums1[i]);
                i++;
                k++;
                nums1.size()--;
            }
        }

        while(nums1.size!=0){
            result.push(nums1[i]);
            k++;
            i++;
            nums1.size--;

        }
        while(nums2.size!=0){
        result.push(nums2[j]);
            k++;
            j++;
            nums2.size--;
        }

        if(result.size()%2!=0)
        {
            return result[result.size()/2];
        }
        else 
        {
            return (result[result.size()/2] +(result[(result.size()/2)-1]/2;
        }
    }
