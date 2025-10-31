import proto
import json
class RuleSet(proto.Message):
  items = proto.MapField(proto.STRING, proto.STRING, number=1)
m={}
try:
 while True:
  a = input()
  b = input()
  if a and b:
   m[a] = b
except EOFError:
 pass

ruleset = RuleSet({'items': m})

b=open('srslist', 'wb')
b.write(RuleSet.serialize(ruleset))
b.close()

b=open('srslist', 'rb')
rul1 = RuleSet.deserialize(b.read())
b.close()

print(str(len(m)) +" rules")

assert (RuleSet.to_dict(rul1) == RuleSet.to_dict(ruleset))

b=open('srslist.json', 'w')
b.write(json.dumps(m))
b.close()
