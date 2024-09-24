/**
 * @param {string} allowed
 * @param {string[]} words
 * @return {number}
 */
var countConsistentStrings = function(allowed, words) {
    let ans=0;

    words.forEach((cur) =>{
        for(letter of cur){
            if(!allowed.includes(letter)){
            ans++;
            break;
           }
        }
    });
    return words.length - ans;
};