int f(int a){
  int a = 3;
  return a;
}

int main(int a){
  a = 2;
  int b = 3 + f(a);
  a = 3 + 2*5 - 4/2;
  return b;
}
