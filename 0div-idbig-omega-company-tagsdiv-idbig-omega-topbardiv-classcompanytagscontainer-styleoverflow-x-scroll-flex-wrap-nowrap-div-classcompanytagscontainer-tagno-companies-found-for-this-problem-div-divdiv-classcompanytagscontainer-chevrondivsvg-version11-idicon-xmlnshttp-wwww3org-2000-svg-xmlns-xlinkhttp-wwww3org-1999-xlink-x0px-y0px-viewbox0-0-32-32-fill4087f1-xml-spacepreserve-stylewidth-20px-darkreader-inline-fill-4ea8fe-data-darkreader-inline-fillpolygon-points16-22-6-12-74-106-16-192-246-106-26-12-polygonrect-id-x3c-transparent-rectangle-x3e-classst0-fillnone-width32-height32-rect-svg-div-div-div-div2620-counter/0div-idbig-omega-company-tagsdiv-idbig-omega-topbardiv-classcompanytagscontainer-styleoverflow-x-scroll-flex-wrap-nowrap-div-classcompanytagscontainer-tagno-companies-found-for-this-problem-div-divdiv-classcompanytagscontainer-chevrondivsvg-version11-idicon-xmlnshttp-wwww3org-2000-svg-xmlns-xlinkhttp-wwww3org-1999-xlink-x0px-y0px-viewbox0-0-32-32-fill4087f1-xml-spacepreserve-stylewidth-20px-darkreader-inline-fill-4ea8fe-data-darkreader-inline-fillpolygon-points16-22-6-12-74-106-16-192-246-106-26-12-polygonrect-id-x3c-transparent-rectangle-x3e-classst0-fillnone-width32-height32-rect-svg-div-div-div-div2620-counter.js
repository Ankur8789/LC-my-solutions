/**
 * @param {number} n
 * @return {Function} counter
 */

var createCounter = function(n) 
{
    var x=n;
    return function() 
    {
       x++;
       return x-1;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */