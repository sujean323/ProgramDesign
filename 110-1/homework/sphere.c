/*The value of radius of the sphere (r) will be given by users.
Please write the fraction 4/3 as 4.0f/3.0f and use 3.14 as the value of pi(£k).
*/

#include <stdio.h>

int main(void){
    float r, volume;

    printf("Enter the radius: ");
    scanf("%f", &r);
    volume = (4.0f/3.0f) * 3.14 * r * r * r;
    printf("The volume of a sphere is %f\n", volume);

    return 0;
}
