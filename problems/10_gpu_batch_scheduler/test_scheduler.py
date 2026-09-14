import unittest
from scheduler import Scheduler, Request
class T(unittest.TestCase):
  def test_full_batch_baseline(self):
    s=Scheduler(max_batch=2,max_wait_ms=10); s.submit(Request('a',0,10,5)); self.assertEqual(s.schedule(1),[]); s.submit(Request('b',1,10,5)); self.assertEqual([x.id for x in s.schedule(1)],['a','b'])
  @unittest.expectedFailure
  def test_wait_bound_target(self):
    s=Scheduler(max_batch=100,max_wait_ms=10); s.submit(Request('a',0,10,5)); self.assertEqual([x.id for x in s.schedule(10)],['a'])
if __name__=='__main__': unittest.main()
