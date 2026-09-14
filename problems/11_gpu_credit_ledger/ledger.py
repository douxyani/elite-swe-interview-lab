class CreditLedger:
    def __init__(self): self.balance=0
    def grant(self, amount:int, valid_from:int, valid_until:int):
        if amount<=0 or valid_until<=valid_from: raise ValueError('invalid grant')
        self.balance += amount  # BUG: ignores window
    def available(self, t:int)->int: return self.balance
    def spend(self, amount:int, t:int)->bool:
        if amount<0 or amount>self.balance: return False
        self.balance -= amount; return True
