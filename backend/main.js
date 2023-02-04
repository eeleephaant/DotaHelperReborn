var gsi = require('./dota2gsi');
require('./telegramIntegration');

const inactivityDuration = 1000 * 15;

var nodeafk = require('afk');
require('./dota2gsi');
const afk = new nodeafk(inactivityDuration);


afk.init();
afk.on('status:idle', () => {
    module.exports.afk = 1;
    console.log(`afk = 1`);
});

afk.on('status:active', () => {
    module.exports.afk = 0;
    console.log(`afk = 0`);
})


