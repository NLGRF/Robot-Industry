void setup() {
  Serial.begin(9600);
  /*
  const int arysz = 6;
  int ary[arysz] = {4, 32, 6, 2, -1, 5};
  int wantedval = -1;
  int wantedpos;
  int len = sizeof(ary)/sizeof(ary[0]);
  for (int i = 0; i < arysz; i++) {
    if (wantedval == ary[i]) {
      wantedpos = i;
      break;
    }
  }
Serial.println(wantedpos);
Serial.println(len);
*/
int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = binarySearch(arr, 0, n-1, x);
   (result == -1)? Serial.println("Element is not present in array")
                 : Serial.print("Element is present at index : ");Serial.println(result);
}

void loop() {

}

int binarySearch(int arr[], int l, int r, int x)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
 
    // Check if x is present at mid
    if (arr[m] == x) 
        return m;  
 
    // If x greater, ignore left half  
    if (arr[m] < x) 
        l = m + 1; 
 
    // If x is smaller, ignore right half 
    else
         r = m - 1; 
  }
 
  // if we reach here, then element was not present
  return -1; 
}
