import unittest
from work_queue import WorkQueue
class T(unittest.TestCase):
  def test_fifo_baseline(self):
    q=WorkQueue(); a=q.enqueue('a'); b=q.enqueue('b'); self.assertEqual(q.pop(),(a,'a')); self.assertEqual(q.pop(),(b,'b'))
  @unittest.expectedFailure
  def test_reservation_target(self):
    q=WorkQueue(); q.enqueue('x'); r=q.reserve(100,10); self.assertEqual(r[0][1],'x')
if __name__=='__main__': unittest.main()
