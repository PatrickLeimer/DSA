int TripleNum(int *num) {
  return (*num) * 3;
}       

int* TimesThree(int &num)
{
  int* ptr = &num;
  num *= 3;
  // cout << ptr << endl;
  return ptr; 
}

int* TripleNum(int num) const
{
  int* ptr = new int; 
  *ptr = num * 3;
  // cout << *ptr << endl;
  return ptr;
}