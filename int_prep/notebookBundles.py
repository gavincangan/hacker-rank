def argsort(seq):
    return [idx for idx,x in sorted(enumerate(seq), key = lambda x: x[1], reverse=True)]

def budgetShopping(n, bundleQuantities, bundleCosts):

    moneyLeft = n
    nbsBought = 0

    done = False
    while(not done):
        minCost = min( bundleCosts )
        maxNbAtStore = [ ( int(moneyLeft/tbundleCost)*bundleQuantities[tStoreIdx], int(moneyLeft/tbundleCost)*bundleCosts[tStoreIdx] ) for tStoreIdx, tbundleCost in enumerate(bundleCosts) ]
        
        # sortedStores = argsort(maxNbAtStore)
        maxNbs, maxLeft = max(maxNbAtStore)
        bestStoreIdxs = [ tStoreIdx for tStoreIdx, tStoreMaxNbs in enumerate(maxNbAtStore) if( tStoreMaxNbs == maxNbs ) ]


        if( moneyLeft < minCost ):
            done = True
            break

        buyNbs = int(moneyLeft / bundleCosts[bestStoreIdx] )

        if(buyNbs > 0):
            nbsBought += buyNbs * bundleQuantities[bestStoreIdx]
            moneyLeft -= buyNbs * bundleCosts[bestStoreIdx]

        bundleQuantities.pop(bestStoreIdx)
        bundleCosts.pop(bestStoreIdx)

        if(bundleCosts):
            pass
        else:
            done = True
            break

    return nbsBought