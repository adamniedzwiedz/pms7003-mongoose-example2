#include "mgos.h"
#include "pms7003.h"

#define UART_NO 0
struct mgos_pms7003* pms7003;

static void pms7003_ready(void *arg) {
  struct pms7003_measure *measure = arg;

  if (measure == NULL) {
    LOG(LL_ERROR, ("Reading measure has failed.\r\n"));
    return;
  }

  LOG(LL_INFO, ("PMS7003 PM_1_0: %ld\r\n", measure->pm1_0_atm));
  LOG(LL_INFO, ("PMS7003 PM_2_5: %ld\r\n", measure->pm2_5_atm));
  LOG(LL_INFO, ("PMS7003 PM_10_0: %ld\r\n", measure->pm10_0_atm)); 
}

static void init_cb(void *arg) {
  LOG(LL_INFO, ("PMS7003 init\r\n"));
  pms7003 = pms7003_init(UART_NO, pms7003_ready, PASSIVE);
  (void) arg;
}

static void read_cb(void *arg) {
  LOG(LL_INFO, ("PMS7003 request read\r\n"));
  if (pms7003 == NULL) return;

  pms7003_request_read(pms7003);
  (void) arg;
}

enum mgos_app_init_result mgos_app_init(void) {
  LOG(LL_INFO, ("PMS7003 test\r\n"));

  // We need to wait on the sensor to run, so the first command must be send with at least 2s delay
  mgos_set_timer(2000 /* ms */, false /* repeat */, init_cb, NULL /* arg */);
  // read PM values every 10 seconds
  mgos_set_timer(10000 /* ms */, true /* repeat */, read_cb, NULL /* arg */);

  return MGOS_APP_INIT_SUCCESS;
}
