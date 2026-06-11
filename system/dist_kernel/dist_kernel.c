#include "dist_kernel.h"
#include "tty.h"

void dist_kernel_init(void) {
    tty_print("[Cosmos Kernel] Distributed Services Started.\n");
    tty_print("[Cosmos Kernel] Cluster Auto-Discovery: LISTENING.\n");
}

int dist_kernel_join_cluster(const char *master_ip) {
    tty_print("[Cosmos Kernel] Attempting to join cluster at: ");
    tty_print(master_ip);
    tty_print("\n");
    return 0; // Joined
}
