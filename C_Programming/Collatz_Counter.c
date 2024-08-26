#include <stdio.h>

int main(){

char v5;
char *Str2 = calloc(10000,sizeof(char));
char *byte_40701F = calloc(10000,sizeof(char));
char *v7 = calloc(10000,sizeof(char));
char *off_4065C0 = "931672ef8007efadcb5edabc82ccf760b4ad1e29249cec6cc0daeb14e340af88f39a8d2b56799fec60266a8adad2f8ee67d793b4fd3fd0ffd73cc6d3bd1eb71f1f14f75f7e71cdad5fe0f5ade07f5fdddbaa4a5451f116b1dd3dd1289a04e50e968bedcaef342de393ea82accad611d1c1b4242d2b3e97ba6aed5561a3d7fa95bc8f799387219d9c1ee660ef2f99888ce5e7e2884d4193540d2b1fd0b5ae8db5b72c7e3536f259a005b63117cbbca05047265105ec5517e46aec2ed5310c177e1e811af680254bad1d7ca0d65ec46aaa315d363abf6a50f3ac5f0709efe8be7fccedc4955eb354dce78d2fb10549407078744164d6102c809ccd50cc87dee85e7aea15b160d4c482e06f253752bd77d8ef87d65c1633ac5383c94fb21b067fdf30aa10bc1f31216940d23924a5761bff2a101893cfccfc6257994ebae30a63934992a16deca856d50596bc1a4504274f6214a3c420396e17ce5edf044344baf4fb2f4c43c90a51b4cafec65661c7274e45b7701b8cb242f7e28133bae0adefa873aa170486cb4";
int index = 0;
  for(int j = 0; v5 = off_4065C0[j >> 1]; j+=2){
    Str2[index] = v5;
    index++;
    if ( j == 40 )
      break;
  }
    printf("%s",Str2);
}