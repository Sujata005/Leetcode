/*void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void sort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
 
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}*/


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize=2;
    int *a=(int *)malloc((*returnSize)*sizeof(int));
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                a[0]=i;
                a[1]=j;
                break;
            }
        }
    }
    
  
    // Instead use qsort() 
    //I will correct the commented part in future
    /*sort(nums,numsSize);
    int l=0,h=numsSize-1;
    while(l<h){
        if(nums[l]+nums[h]>target) h--;
        else if(nums[l]+nums[h]==target){
            a[0]=l;
            a[1]=h;
            break;
        }
        else l++;
    }*/
    return a;
}
