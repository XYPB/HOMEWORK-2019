from __future__ import print_function
import pandas as pd
pd.__version__
cn = pd.Series(['SF', 'SJ', 'Sa'])
cp = pd.Series([10000, 20000, 347594])
cd = pd.DataFrame({'CN': cn, 'Pop': cp})
# print(cd.describe())
# print(cd)
# print(cn)
# print(cd.head)
print(cp + 100)
# print(cd[0: 2])
