# hw4 - Exercise1
# writer : 21700760 Juyoung Ha

import pandas as pd
import numpy as np

# read data from csv file
init = pd.read_csv('titanic_train.csv', index_col='Sex')

# find surviver
mask = (init.Survived == 1)
surviver = init[mask][['Pclass', 'Survived']]

# rearrange data and calcuate sum of surviver
result = surviver.groupby(['Sex', 'Pclass']).sum()
sCount = np.array(result)

for i in range(0, len(result)):
    print('group: (\'%s\', %d) => %d' % (result.index[i][0], result.index[i][1], sCount[i]))