#include <freehdl/kernel-wait-info.hh>
#include <freehdl/kernel-reader-info.hh>


wait_info::wait_info(int id, process_base *proc)
{
  wait_id = id;
  process = proc;
}


