#include <stdio.h>

class Shapes {
private:
    double length, breadth, height; 

public:
    // Function to set values
    void setValues(double a, double b = 0, double c = 0) {
        length = a;
        breadth = b;
        height = c;
    }

    // Function to calculate square area
    void squareArea() {
        printf("Square Area: %.2f\n", length * length);
    }

    // Function to calculate cube surface area
    void cubeSurfaceArea() {
        printf("Cube Surface Area: %.2f\n", 6 * length * length);
    }

    // Function to calculate rectangle area
    void rectangleArea() {
        printf("Rectangle Area: %.2f\n", length * breadth);
    }

    // Function to calculate cuboid surface area
    void cuboidSurfaceArea() {
        double area = 2 * (length * breadth + breadth * height + height * length);
        printf("Cuboid Surface Area: %.2f\n", area);
    }
};

int main() {
    int choice = 0;
    double x, y, z;
    Shapes shape;  

    while (choice != 5) {
        
        printf("\nMenu:\n1. Square\n2. Cube\n3. Rectangle\n4. Cuboid\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter side length: ");
                scanf("%lf", &x);
                shape.setValues(x);
                shape.squareArea();
                break;

            case 2:
                printf("Enter side length: ");
                scanf("%lf", &x);
                shape.setValues(x);
                shape.cubeSurfaceArea();
                break;

            case 3:
                printf("Enter length and breadth: ");
                scanf("%lf %lf", &x, &y);
                shape.setValues(x, y);
                shape.rectangleArea();
                break;

            case 4:
                printf("Enter length, breadth, and height: ");
                scanf("%lf %lf %lf", &x, &y, &z);
                shape.setValues(x, y, z);
                shape.cuboidSurfaceArea();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
