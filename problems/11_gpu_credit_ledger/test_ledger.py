import unittest
from ledger import CreditLedger
class T(unittest.TestCase):
  def test_baseline(self):
    l=CreditLedger(); l.grant(100,0,10); self.assertTrue(l.spend(40,1)); self.assertEqual(l.available(1),60)
  @unittest.expectedFailure
  def test_expiry_target(self):
    l=CreditLedger(); l.grant(100,0,10); self.assertEqual(l.available(10),0)
if __name__=='__main__': unittest.main()
