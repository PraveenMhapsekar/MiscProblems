#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define SIZE 4096
#define REC_NUM 50

char fileName1[50] = "dataset1.csv" ;
char fileName2[50] = "dataset2.csv" ;

typedef struct {
	char name[50];
	float legLen;
	char diet[50];
} f1_t;

typedef struct {
	char name[50];
	float strideLen;
	char stance[50];
} f2_t;

typedef struct {
	char name[50];
	float legLen;
	char diet[50];
	float strideLen;
	char stance[50];
	float speed;
} f3_t;

f1_t f1[REC_NUM];
f2_t f2[REC_NUM];
f3_t f3[REC_NUM];

#define VFMT " %29[^ ,\n\t]"

int 
readFileToArr() {
	char buf[SIZE]; 
	int i = 0; 
  int k = 0;
	FILE *fptr; 

	// first file processing  
	fptr = fopen(fileName1, "r");
	if (ferror(fptr)) {
		perror("fopen");
		return -1;
	}

	while (fgets(buf, SIZE, fptr)) {
 	  sscanf(buf, "%19[^,]"",""%f"",""%19[^ \n\t]",f1[i].name, &f1[i].legLen, f1[i].diet);
	  i++;
	}

	fclose(fptr);

  printf ("\n\nProccesing second file:\n");
	// second file processing
	k = 0;
	fptr = fopen(fileName2, "r");
	if (ferror(fptr)) {
		perror("fopen");
		return -1;
	}

	while (fgets(buf, SIZE, fptr)) {
		sscanf(buf, "%29[^,]"",""%f"",""%29[^ \n\t]",f2[k].name, &f2[k].strideLen, f2[k].stance);
		k++;
	}
  
	fclose(fptr);
  if (i != k) 
    // Number of records in both files are not matching, return error
    return -1;

  return i - 1;
}

int 
sortArr1(int count) {
	f1_t temp;
	int i, j;
	for (i = 0; i <= count; i++){
		for (j = i + 1; j <= count; j++){
			if (strcmp(f1[i].name, f1[j].name) > 0) {
				temp = f1[i];
				f1[i] = f1[j];
				f1[j] = temp;
			}
    }
	}

  printf("\nsorted Arry:\n");
	for (i = 0; i <= count; i++) {
	  printf("%s %f %s\n", f1[i].name, f1[i].legLen, f1[i].diet);
  }
}

int 
sortArr2(int count) {
	f2_t temp;
	int i, j;
	for (i = 0; i <= count; i++) {
		for (j = i+1; j <= count; j++) {
			if (strcmp(f2[i].name, f2[j].name) >0){
				temp = f2[i];
				f2[i] = f2[j];
				f2[j] = temp;
			}
    }
	}

  printf ("\nsorted Arry:\n");
	for (i = 0; i <= count; i++) {
	  printf("%s %f %s\n", f2[i].name, f2[i].strideLen, f2[i].stance);
  }
}

int 
sortArr3(int count) {
	f3_t temp;
	int i, j;
	for (i = 0; i <= count; i++) {
		for (j = i+1; j <= count; j++) {
			if (f3[i].speed > f3[j].speed) {
				temp = f3[i];
				f3[i] = f3[j];
				f3[j] = temp;
			}
    }
	}

  printf ("\n%s Arry Sorted on Speed:\n", __FUNCTION__);

  printf ("\nname\t\t\t\tspeed\t\tstance\n");
	for (i = 0; i <= count; i++) {
		printf("%s\t\t\t%f\t%s\n", f3[i].name, f3[i].speed, f3[i].stance);
  }
}

/*
 Given the following formula, speed = ((STRIDE_LENGTH / LEG_LENGTH) - 1) * SQRT(LEG_LENGTH * g)
 Where g = 9.8 m/s^2 (gravitational constant) 
*/
int 
mergeArray(int count) {
  printf("%s\n", __FUNCTION__);
	int i, j;
	for(i = 0; i <= count; i++){
		strcpy(f3[i].name, f1[i].name);  
		f3[i].legLen = f1[i].legLen;
		strcpy(f3[i].diet, f1[i].diet);
		f3[i].strideLen = f2[i].strideLen;
	 	strcpy(f3[i].stance, f2[i].stance);
		//f3[i].speed = (((f2[i].strideLen / f1[i].legLen) - 1) * sqrtf((f1[i].legLen * 9.8))) ;
		f3[i].speed = (((f2[i].strideLen / f1[i].legLen) - 1) * ((f1[i].legLen * 9.8))) ;
		printf("%s\t\t\t%f\t%s\n", f3[i].name, f3[i].speed, f3[i].stance);
  }
}

void
printSelectedKey( int count, char *key, char *filename) {
  FILE *fptr;
  fptr = fopen(filename, "w+");
  if (ferror(fptr)) {
    perror("printSelectedKey");
    return;
  } 
  printf("\n\nPrinting filtered entries matching key[%s]:\n",key);

  printf ("\nname\t\t\tspeed\tstance\n");
	int i;
	for(i = 0; i <= count; i++){
		if (strcmp(f3[i].stance, key) == 0) {
		  printf("%-20s %2.3f\t%s\n", f3[i].name, f3[i].speed, f3[i].stance);
      fprintf(fptr, "%-20s %2.3f\t%s\n", f3[i].name, f3[i].speed, f3[i].stance);
		}
   }
   fclose(fptr);
}

int 
main() {
  int num;
  char buf[200];
  // read files into array's A1[] & A2[]
  num = readFileToArr();
  if (num <= 0 ) {
     fprintf(stderr, "readFileToArr"); 
     return num;
   }

  // sortArray A1[]
   sortArr1(num);

  // sortArray A2[]
   sortArr2(num);

  // Merge sorted array A1[] and A2[] in A3[]
  // Compute speed and store in A3[]
  mergeArray(num);

  // Sort A3[] on 'speed'
   sortArr3(num);

  // print sorted A3[] with meeting criteria
  printSelectedKey(num, "bipedal", "output.txt");

  FILE *fp = fopen("output1.txt", "w+");
  if (ferror(fp)) {
    perror("main");
  }
  
  fseek(fp, 23, SEEK_SET);
  fread(buf, 100, 1, fp);
  fprintf(stdout, "printing after fseek\n");
  fprintf(stdout, "%s\n", buf);

  fseek(fp, -23, SEEK_CUR);
  fread(buf, 100, 1, fp);
  fprintf(stdout, "printing after fseek\n");
  fprintf(stdout, "%s\n", buf);

   system("sort -m f1.csv f2.csv > f3.csv");

	return 0;
}
