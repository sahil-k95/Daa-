 #include<iostream>
using namespace std;
int particion(int arr[],int si,int ei){
   int pivot= arr[si];
int count=0;
  for(int i=si+1;i<=ei;i++){ // yahn i=si+1 h kyn ki hum 1 element chor k naa smallelement ka search start krenge 
      if(arr[i]<=pivot){
          count++;
      }
  }
    int pivotindexlocation= si+count;  // yahn se exact pivot element ka location milega array mai pivot se chota elemet ko count karnenge.
    swap(arr[pivotindexlocation],arr[si]);// swap krke pivot element ko sahi jagaha rakh dange

    // ab right and left part par aate h
    int i=si,j=ei;
    while(i<pivotindexlocation && j>pivotindexlocation){
        // yahn aake i>>> riht side aage ki condn par chk krke aage badhayenge aur i++ krenge
        while(arr[i]<=arr[pivotindexlocation]){
            i++;
        }
        // yahn aake <<<j left side aage ki condn par chk krke aage badhayenge aur j-- krenge
        while(arr[j]>arr[pivotindexlocation]){
            j--;
        }
        // swap tavi krenge jab iaur j sahi position par nhi hoga
           if(i<pivotindexlocation && j>pivotindexlocation){
               swap(arr[i++],arr[j--]);
           } 
    }
    return pivotindexlocation; //ans m index retun kar dange

}


 void helperquicksort(int arr[],int si,int ei){

     if(si>=ei){
         return;
     }
     // particion krenge
     int p= particion(arr,si,ei);
    //yahn quicksort particion element se ek pahle element tak call krenge
      helperquicksort(arr,si,p-1);
     // particion k ek baad se call krenge end tak 
      helperquicksort(arr,p+1,ei);

 }


void quickSort(int input[], int size) {
    if(size<=1){
        return;
    }
  helperquicksort(input,0,size-1);
}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete [] input;

}


//given below  samples to use after code got compiled 
//Sample Input 1 :
//6 
//2 6 8 5 4 3
//Sample Output 1 :
//2 3 4 5 6 8
//Sample Input 2 :
//5
//1 5 2 7 3
//Sample Output 2 :
//1 2 3 5 7
