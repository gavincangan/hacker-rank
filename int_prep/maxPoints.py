def maxPoints(elements):
    # Write your code here

    retMaxPoints = 0
    uniqueElements = set()
    for tElement in elements:
        uniqueElements.add(tElement)
    
    countElements = {}
    for tElement in elements:
        if(tElement not in countElements):
            countElements[tElement] = 0
        countElements[tElement] += 1
    
    while(uniqueElements):
        pointsElements = {}
        for tElement in uniqueElements:
            pointsElements[tElement] = tElement * countElements[tElement]
            if( (tElement - 1) in uniqueElements ):
                pointsElements[tElement] -= (tElement - 1) * countElements[(tElement - 1)]
            if( (tElement + 1) in uniqueElements ):
                pointsElements[tElement] -= (tElement + 1) * countElements[(tElement + 1)]
            
        tmaxElement = list(uniqueElements)[0]
        tmaxPoints = pointsElements[tmaxElement]
        for tElement in uniqueElements:
            if(pointsElements > tmaxPoints):
                tmaxElement = tElement
                tmaxPoints = pointsElements[tElement]
        
        retMaxPoints += tmaxElement * countElements[tmaxElement]
        uniqueElements.remove(tmaxElement)

    return retMaxPoints

if __name__=="main":
    print( maxPoints([ 3, 3, 4, 2 ] ) )