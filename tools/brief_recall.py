#!/usr/bin/env python3
import os, sys, time
from pathlib import Path

if len(sys.argv) not in (2,3):
    raise SystemExit("usage: brief_recall.py PATH [SECONDS]")
path=Path(sys.argv[1]); seconds=int(sys.argv[2]) if len(sys.argv)==3 else 90
text=path.read_text()
print(text)
print(f"\n--- You have {seconds}s. When time expires the screen will clear. ---", flush=True)
time.sleep(seconds)
os.system('cls' if os.name=='nt' else 'clear')
print("Without reopening the brief, write:\n1) API / requested output\n2) five constraints\n3) three ambiguity questions\n4) two invariants\n5) likely bottleneck\n")
input("Press Enter only after you have written your recall notes...")
print("\n--- ORIGINAL BRIEF ---\n")
print(text)
