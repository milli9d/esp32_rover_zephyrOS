/**
 * @brief Janitor Workqueue
 *
 * This takes care of any and all maintainance tasks.
 *
 *
 */

#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>

LOG_MODULE_DECLARE(JANITOR);

namespace robocar {

class janitor_wq
{
  private:
    /* data */
  public:
    janitor_wq(/* args */);
    ~janitor_wq();
};

janitor_wq::janitor_wq(/* args */) {}

janitor_wq::~janitor_wq() {}

} // namespace robocar