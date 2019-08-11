#include <freehdl/kernel-flags.hh>

#ifdef PERFMON_STATISTICS

#include <iostream>

extern "C" {
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <stropts.h>
#include <fcntl.h>
#include <math.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/processor.h>
#include <sys/procset.h>
#include "../perfmon/perfmon.h"
	   }

#include <freehdl/kernel-pcounter.hh>


int cpu = 0, rc, fd;
unsigned long long tmp;
hrtime_t start, end;
unsigned long long a, b;
unsigned long x, y;
int pcode_num;


struct performance_codes {
  unsigned long long code;
  char *description1, *description2, *description3;
  char *command;
};


const char *performance_command_code = "-pc";
const int performance_code_count = 5;
performance_codes pcodes[performance_code_count] = {
  { PCR_S0_DC_READ | PCR_S1_DC_READ_HIT | PCR_USER_TRACE, 
    "D-Cache read operations ", "D-Cache read hits", "D-Cache read hit rate", "dcache_read" },  
  { PCR_S0_DC_WRITE | PCR_S1_DC_WRITE_HIT | PCR_USER_TRACE, 
    "D-Cache write operations", "D-Cache write hits", "D-Cache write hit rate", "dcache_write" }, 
  { PCR_S0_IC_REF | PCR_S1_IC_HIT | PCR_USER_TRACE, 
    "I-Cache reads", "I-Cache hits",  "I-Cache hit rate", "icache"},
  { PCR_S0_STALL_LOAD | PCR_S1_DC_READ_HIT | PCR_USER_TRACE, 
    "Instructions stalls caused by load operations", "D-Cache read hits", "rate ", "dcache_stall" },
  {  PCR_S0_INSTR_CNT | PCR_S1_CYCLE_CNT | PCR_USER_TRACE, 
    "completed instructions", "cycles", "CPI rate", "cpi" },
};


void plot_pccodes()
{
  cout << "Possible peformance counter configurations:" << endl;
  for (int i = 0; i < performance_code_count; i++)
    cout << "\t" << pcodes[i].command << endl;
}


char *
format_long(unsigned long i)
{
  static char buffer1[100], buffer2[100];
  sprintf(buffer1, "%lu", i);
  int size = strlen(buffer1);
  int counter = size;
  for (int j = 0, k = 0; j < size; j++, k++, counter--) {
    buffer2[k] = buffer1[j];
    if ((counter - 1) % 3 == 0 && counter > 1) {
      buffer2[++k] = ',';
    }
  }
  return buffer2;
}

int
pcode_lookup(int argc, char *argv[])
{
  int i = 0;
  for (; i < argc; i++)
    if (!strcmp(performance_command_code, argv[i]))
      break;

  if (i == argc)
    return 0;

  if (i + 1 >= argc) {
    cout << "Missing performance code argument!" << endl;
    plot_pccodes();
    return 0;
  }

  int index = i + 1;
  for (int i = 0; i < performance_code_count; i++)
    if (!strcmp(pcodes[i].command, argv[index]))
      return i;

  cout << "Unknown performance code argument!" << endl;
  plot_pccodes();
}


void
start_pcounter(int argc, char *argv[])
{
  /* Try to bind us to the given CPU */
  cpu = 0;
  rc = processor_bind(P_PID, P_MYID, cpu, NULL);
  if (rc == -1) {
    perror("processor_bind()");
    exit(1);
  }
  /* Try to open a channel to the perfmon driver */
  fd = open("/dev/perfmon", O_RDONLY);
  if (fd == -1) {
    perror("open(/dev/perfmon)");
    exit(1);
  }
  
  /* Set PCR to accumulate the various events */
  pcode_num = pcode_lookup(argc, argv);
  rc = ioctl(fd, PERFMON_SETPCR, &pcodes[pcode_num].code);

  if (rc < 0) {
    perror("ioctl(PERFMON_SETPCR)");
    exit(1);
  }
  
  start = gethrtime();
  clr_pic();
  cpu_sync();
  a = get_pic();
}


void
end_pcounter()
{
  cpu_sync();
  b = get_pic();
  
  end = gethrtime();
  
  x = extract_pic0(b) - extract_pic0(a); /* D-Cache reads */
  y = extract_pic1(b) - extract_pic1(a); /* D-Cache read-Hits */
  cout << "Wall clock time used: " << (end - start) / (double)1000000 << endl;
  cout << "Number of " << pcodes[pcode_num].description1 << " : " << format_long(x) << endl;
  cout << "Number of " << pcodes[pcode_num].description2 << " : " << format_long(y) << endl;
  cout <<  pcodes[pcode_num].description3 << " : " << (double)y/(double)x << endl;

  close(fd);
}


#endif
