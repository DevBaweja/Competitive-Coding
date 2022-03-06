// Hashing
function add(mp, key, val) {
    if (mp[key]) mp[key] += val;
    else mp[key] = val;
}
let subdomainVisits = function (cpdomains) {
    let mp = {};
    cpdomains.map(cpdomain => {
        let [count, subdomain] = cpdomain.split(' ');
        count = parseInt(count);
        subdomain = subdomain.split('.');
        if (subdomain.length == 2) {
            const [first, second] = subdomain;
            add(mp, second, count);
            add(mp, subdomain.join('.'), count);
        } else {
            const [first, second, third] = subdomain;
            add(mp, third, count);
            add(mp, second + '.' + third, count);
            add(mp, subdomain.join('.'), count);
        }
    });

    return Object.entries(mp).map(([key, value]) => value + ' ' + key);
};

// Generalised
function add(mp, key, val) {
    if (mp.hasOwnProperty(key)) mp[key] += val;
    else mp[key] = val;
}
let subdomainVisits = function (cpdomains) {
    let mp = {};
    cpdomains.map(cpdomain => {
        let [count, subdomain] = cpdomain.split(' ');
        count = parseInt(count);
        subdomain = subdomain.split('.');
        while (subdomain.length) {
            let moredomain = subdomain.join('.');
            add(mp, moredomain, count);
            subdomain.shift();
        }
    });

    return Object.entries(mp).map(([key, value]) => value + ' ' + key);
};
