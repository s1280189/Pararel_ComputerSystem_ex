#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *fp;
  char fname[]="height.txt";
  int nx=1000,ny=1000;
  float data[nx][ny];
  float f_data;
  int nxy_number[2];
  char str[nx];
  int count=0;
  float result=0;

  for(int i=0;i<nx;i++){
    for(int j=0;j<ny;j++){
      data[i][j]=0;
    }
  }
  
  fp=fopen(fname, "r");
  if(fp==NULL){
    printf("%s file not open\n",fname);
    return -1;
  }

  fscanf(fp, "%f", nx);
  fscanf(fp, "%f", ny);
  for(int i=0;i<nx;i++){
    for(int j=0;j<ny;j++){
      if(fscanf(fp, "%f",data[i][j]) ==EOF)
	continue;
    }
  }
  fclose(fp);
  
  //x-direction
  for(int i=0;i<nx;i++){
    for(int j=0;j<ny;j++){
      result=result+data[i][j];
    }
  }
  printf("x-direction: %f\n",result);

  //y-direction
  result=0;
  for(int j=0;j<ny;j++){
    for(int i=0;i<nx;i++){
      result=result+data[i][j];
    }
  }
  printf("y-direction: %f\n",result);

  

  return 0;
}
