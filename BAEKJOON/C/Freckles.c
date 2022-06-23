#include <stdio.h>
#include <math.h>

struct Point2D {
    float x;
    float y;
};

int main()
{
    struct Point2D point[100];
    struct Point2D lowPoint;
    int n,ind;
    double distance;
    double lowDistance = 1000;
    double sum = 0;
    
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
        scanf("%f %f", &point[i].x, &point[i].y);
    }
    lowPoint.x = point[0].x;
    lowPoint.y = point[0].y;
    for(int i = 1;i <= sizeof(point) / sizeof(struct Point2D); i++) {
        for(int j = 1; j <= sizeof(point) / sizeof(struct Point2D); j++) {
        int a = point[j].x - lowPoint.x;
        int b = point[j].y - lowPoint.y;
        distance = sqrt((a*a) + (b*b));
        if (distance < lowDistance) {
                lowDistance = distance;
                lowPoint.x = point[j].x;
                lowPoint.y = point[j].y;
                ind = j;
        }
        }
        point[ind].x = 100000;
        point[ind].y = 100000;
        sum += lowDistance;
    }
    
    
    return 0;
}