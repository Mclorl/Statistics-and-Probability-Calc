#include<stdio.h>
#include<math.h>
#include<string.h>

int Input_Value_X[1000];
int Input_Value_Y[1000];

void usr_Input_Function(int *n_Value);
void correlation_Table(int n_Value);
void interpretation(double r_Value);
int main(void) {

   int Input_Value_n;

   usr_Input_Function(&Input_Value_n);
   correlation_Table(Input_Value_n);

   return 0;
}

void usr_Input_Function(int *n_Value) {
   printf("Value of n: ");
   scanf("%d", n_Value);

   for (int i = 0; i < *n_Value; i++) {   // Determine the value of X and Y of n
      printf("Enter the value of X%d:", i+1);
      scanf("%d", &Input_Value_X[i]);
   }
   for (int j = 0; j < *n_Value; j++) {
      printf("Enter the value of Y%d:", j+1);
      scanf("%d", &Input_Value_Y[j]);
   }
}

void correlation_Table(int n_Value) {
   int Sum_Value_X = 0;
   int Sum_Value_Y = 0;
   int Sum_Value_XY = 0;
   int Sum_Value_X2 = 0;
   int Sum_Value_Y2 = 0;

   int arr_XY[n_Value];
   int arr_X2[n_Value];
   int arr_Y2[n_Value];

   double r;


   for (int i = 0; i < n_Value; i++) {
      arr_XY[i] = Input_Value_X[i] * Input_Value_Y[i];
      arr_X2[i] = Input_Value_X[i] * Input_Value_X[i];
      arr_Y2[i] = Input_Value_Y[i] * Input_Value_Y[i];
   }

   for (int j = 0; j < n_Value; j++) {
      Sum_Value_X = Sum_Value_X + Input_Value_X[j];
      Sum_Value_Y = Sum_Value_Y + Input_Value_Y[j];
      Sum_Value_XY = Sum_Value_XY + arr_XY[j];
      Sum_Value_X2 = Sum_Value_X2 + arr_X2[j];
      Sum_Value_Y2 = Sum_Value_Y2 + arr_Y2[j]; 
   }
   int Sum_Value_X_Square = Sum_Value_X * Sum_Value_X;
   int Sum_Value_Y_Square = Sum_Value_Y * Sum_Value_Y;
   double rDeno = sqrt(((n_Value*Sum_Value_X2) - Sum_Value_X_Square)*((n_Value*Sum_Value_Y2) - Sum_Value_Y_Square));
   r = (((n_Value * Sum_Value_XY)-(Sum_Value_X*Sum_Value_Y))/(rDeno));

   printf("\n\n\n*************************************************\n*\tX\tY\tXY\tX2\tY2\t*\n");
   for (int n = 0; n < n_Value; n++) {
      printf("*\t%d\t%d\t%d\t%d\t%d\t*\n", Input_Value_X[n], Input_Value_Y[n], arr_XY[n], arr_X2[n], arr_Y2[n]);
   }
   printf("*-----------------------------------------------*\n*\t%d\t%d\t%d\t%d\t%d\t*\n*************************************************\n\n\n", Sum_Value_X, Sum_Value_Y, Sum_Value_XY, Sum_Value_X2, Sum_Value_Y2);

   interpretation(r);
}

void interpretation(double r_Value) {
   char sign_r[10];
   char qualitative_description[100];
   double abs_r = fabs(r_Value);

   if (r_Value != abs_r) {
      strcpy(sign_r, "negative");
   } else {
      strcpy(sign_r, "positive");
   }
   
   if (abs_r == 1) {strcpy(qualitative_description, "Perfect");}
   else if (abs_r < 1 && abs_r > 0.75) {strcpy(qualitative_description, "Very high");}
   else if (abs_r < 0.75 && abs_r > 0.50) {strcpy(qualitative_description, "Moderately high");}
   else if (abs_r < 0.50 && abs_r > 0.25) {strcpy(qualitative_description, "Moderately low");}
   else if (abs_r < 0.25 && abs_r > 0) {strcpy(qualitative_description, "Very low");}
   else if (abs_r == 0) {strcpy(qualitative_description, "No");}

   printf("Value of r = %.2f - %s %s correlation\n",r_Value, qualitative_description, sign_r);
}
