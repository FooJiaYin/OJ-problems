#include <stdio.h>

struct Knight {
    int damage, health, attackCount, totalDamage;
    struct Knight *head, *next, *prev;
};

void attack(struct Knight *attacker, struct Knight *target) {
    if (attacker->health <= 0 || target->health <= 0 ||
        attacker->head == target->head)
        return;
    target = target->head;
    attacker = attacker->head;
    target->totalDamage += attacker->totalDamage;

    // Reduce all target knights health
    struct Knight *prevTarget;
    while (1) {
        target->health -= attacker->totalDamage;
        if (target->health <= 0) {
            // Remove target from list
            if (prevTarget) prevTarget->next = target->next;
            target->head->totalDamage -= target->damage;
        }
        if (!(target->next)) break;
        prevTarget = target;
        target = target->next;
    }
    target->next = attacker;
    // Move all attacker knights to target
    while (1) {
        attacker->attackCount++;
        attacker->head = target->head;
        if (!(attacker->next)) break;
        attacker = attacker->next;
    };
}

int main() {
    struct Knight knights[20];
    int healths[] = {39, 59, 54, 45, 39, 56, 55, 41, 52, 46,
                     58, 42, 41, 40, 42, 53, 57, 53, 32, 42};
    int damages[] = {15, 28, 28, 24, 25, 4,  15, 6,  17, 11,
                     11, 11, 16, 25, 15, 14, 24, 26, 29, 24};
    for (int i = 0; i < 20; i++) {
        knights[i].health = healths[i];
        knights[i].damage = damages[i];
        knights[i].attackCount = 0;
        knights[i].totalDamage = damages[i];
        knights[i].head = &knights[i];
        knights[i].next = NULL;
    }

    attack(&knights[18 - 1], &knights[1 - 1]);
    attack(&knights[19 - 1], &knights[16 - 1]);
    attack(&knights[20 - 1], &knights[5 - 1]);
    attack(&knights[6 - 1], &knights[13 - 1]);
    attack(&knights[2 - 1], &knights[9 - 1]);
    attack(&knights[15 - 1], &knights[14 - 1]);
    attack(&knights[7 - 1], &knights[4 - 1]);
    attack(&knights[11 - 1], &knights[17 - 1]);
    attack(&knights[3 - 1], &knights[10 - 1]);
    attack(&knights[12 - 1], &knights[8 - 1]);

    // Print attack count
    for (int i = 0; i < 20; i++) {
        printf("%d ", knights[i].attackCount);
    }
    printf("\n");

    return 0;
}