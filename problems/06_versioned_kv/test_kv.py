import unittest
from kv import VersionedKV
class T(unittest.TestCase):
    def test_latest_baseline(self):
        db=VersionedKV(); db.set("a","x",1); self.assertEqual(db.get("a"),"x"); db.delete("a",2); self.assertIsNone(db.get("a"))
    @unittest.expectedFailure
    def test_history_target(self):
        db=VersionedKV(); db.set("a","old",10); db.set("a","new",30); db.set("a","mid",20)
        self.assertEqual(db.get_at("a",25),"mid")
if __name__=='__main__': unittest.main()
