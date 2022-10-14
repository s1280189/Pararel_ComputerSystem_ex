#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  FILE *fp;
  char fname[]="height.txt";
  int nx=1000,ny=1000;
  float data[nx][ny];
  float f_data;
  int nxy_number[2];
  char str[nx][ny];
  char* ptr;
  int count=0;
  float result=0;
  float big_data[nx*ny];

 
  
  fp=fopen(fname, "r");
  if(fp==NULL){
    printf("%s file not open\n",fname);
    return -1;
  }

  fscanf(fp, "%f", nx);
  fscanf(fp, "%f", ny);
 for(int i=0;i<nx;i++){
    for(int j=0;j<ny;j++){
      fscanf(fp, "%s", str[i]);
    }
  }
  int j=0;
  for(int i=0;i<nx;i++){
    ptr=strtok(str[i],",");
    data[i][j]=strtof(ptr,NULL);
    j++;
    while(ptr != NULL){
      ptr = strtok(NULL, ",");
      data[i][j]=strtof(ptr,NULL);
      j++;
    }
    j=0;
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


  //create big_data
  int k = 0;
    for(int i=0;i<nx;i++){
      for(int j=0;j<ny;j++){
	big_data[k]=data[i][j];
	k++;
      }
    }

    //ascending
    float tmp;
    for(int i=0;i<k;i++){
      for(int j=i+1;j<k;j++){
	if(big_data[i]>big_data[j])
	  {
	    tmp=big_data[i];
	    big_data[i]=big_data[j];
	    big_data[j]=tmp;
	  }
      }
    }
    result=0;

    for(int i=0;i<k;i++){
      result=result+big_data[i];
    }
    printf("ascending: %f\n",result);

    //descending
     for(int i=0;i<k;i++){
       for(int j=i+1;j<k;j++){
	if(big_data[i]<big_data[j])
	  {
	    tmp=big_data[i];
	    big_data[i]=big_data[j];
	    big_data[j]=tmp;
	  }
      }
    }
    result=0;

    for(int i=0;i<k;i++){
      result=result+big_data[i];
    }

     printf("descending: %f\n",result);

  

  return 0;
}
