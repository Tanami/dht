/*
 * Copyright (c) 2003 [NAMES_GO_HERE]
 *                    Massachusetts Institute of Technology
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __VIVALDITEST_H
#define __VIVALDITEST_H

#include "p2psim/p2protocol.h"
#include "vivaldinode.h"

class VivaldiTest : public VivaldiNode {
public:
  VivaldiTest(IPAddress i, Args &args);
  ~VivaldiTest();
  string proto_name() { return "VivaldiTest"; }

  virtual void join(Args*);
  virtual void leave(Args*) { }
  virtual void crash(Args*) { }
  virtual void insert(Args*) { }
  virtual void lookup(Args*) { }
  virtual void initstate ();
  void tick(void *);
  void status();
  double error();
  vector<IPAddress> best_n (unsigned int n);
  void total_error(double &x05, double &x50, double &x95);
  vector<IPAddress> _nip_best;
  vector<IPAddress> _nip;

 private:
  int _ticks;
  Vivaldi *_vivaldi;
  static vector<VivaldiTest*> _all;

  int _next_neighbor;
  int _neighbors; // if > 0, fix the number of neighbors
  int _total_nodes;
  int _vis;

  uint _old_all_size;

  void handler(void *, void *);

  void addNeighbors ();
  void print_all_loc();
};

#endif // __VIVALDITEST_H
