/*Write a program that takes the x-y coordinates of a point in the Cartesian plane
and prints a message telling:
(1) Either an axis on which the point lies or the quadrant in which it is found.
The program also needs to tell if the input point is at the origin (0, 0).
(2) The value of squared distance between this point and the origin (0, 0). Please
use Pythagorean theorem to compute the squared distance.*/

#include<stdio.h>

int main(){

    int x, y;

    printf("Enter the point (x,y): \n");
    scanf("%d%d", &x, &y);//input

    if(x==0 && y==0){
        printf("The point is at the origin (0,0)\nThe value of squared distance is 0");
        }
    else if(x>0 && y>0){
        printf("The point is in the Quadrant I\nThe value of squared distance is %d\n", x*x+y*y);
        }
    else if(x<0 && y>0){
        printf("The point is in the Quadrant II\nThe value of squared distance is %d\n", x*x+y*y);
    }
    else if(x<0 && y<0){
        printf("The point is in the Quadrant III\nThe value of squared distance is %d\n", x*x+y*y);
    }
    else if(x>0 && y<0){
        printf("The point is in the Quadrant IV\nThe value of squared distance is %d\n", x*x+y*y);
    }
    else if(x!=0 && y==0){
        printf("The point is on the x-axis\nThe value of squared distance is %d\n", x*x+y*y);
    }
    else if(x==0 && y!=0){
        printf("The point is on the y-axis\nThe value of squared distance is %d\n", x*x+y*y);
    }
    //check squadrant and squared distance

    return 0;
}
