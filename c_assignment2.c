//BETUL CAM
#include <stdio.h>
#include <stdlib.h>
int gain(int segment, char ring){
    if(ring == 'S') return segment;
    if(ring == 'D') return segment*2;
    if(ring == 'T') return segment*3;
    if(ring == 'O') return 25;
    else return 50; // Inner ring
}
int point(int p, int s, char r){ // p: point s: segment, r: ring
    if(p - gain(s, r) > 1) return p - gain(s, r);
    else{
        if (r == 'D'&& p - gain(s, r) >= 0){
            return p - gain(s, r);
        }
        else return p;
    }
}
int main(){
    int target, segment;
    char ring;

    printf("Target: ");
    scanf("%d", &target);
    printf("\n");
    printf("Throw: ");
    scanf("%d %c", &segment, &ring);
    while (ring != 'D'){
        printf("Points: %d\n", target);
        printf("Throw: ");
        scanf("%d %c", &segment, &ring);
    }
    target = point(target, segment, ring);
    printf("Points: %d\n", target);
    while (target != 0){
        printf("Throw: ");
        scanf("%d %c", &segment, &ring);
        target = point(target, segment, ring);
        printf("Points: %d\n", target);
    }
    
    return EXIT_SUCCESS;
}