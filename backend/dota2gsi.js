var d2gsi = require("dota2-gsi");
var telegram = require("./telegramIntegration");
var config = require("./config.json");
var main = require("./main");
var net = require("net");

var hero, gpm, maptime, activity;
maptime = "Undefined";

var server = new d2gsi();

let _client;

function sleep(ms) {
    return new Promise((resolve) => {
        setTimeout(resolve, ms);
    });
}

async function InitSocket() {
    var unixServer = await net.createServer((client) => {
        _client = client;
        console.log("Client connected!");
        client.on("end", () => {
            console.log("Client disconnected!");
            unixServer.close();
        });
    });
    unixServer.listen("/home/dotagsi123", () => {
        console.log("socket bound");
    });
}

server.events.on("newclient", async (client) => {
    InitSocket();

    console.log("New connection!");

    client.on("player:activity", (activity) => {
        if (activity == "playing" && main.afk == 1) {
            telegram.bot.telegram.sendMessage(
                config.chatid,
                "[Dota 2] Игра запущена (до горна)"
            );
            console.log(activity);
        }
    });
    client.on("map:clock_time", (time) => {
        maptime = time;
        console.log(time);
        if (_client != undefined) {
            _client.write(`t:${time}`);
            _client.pipe(client);
        }
        if (time == 0 && main.afk == 1) {
            telegram.bot.telegram.sendMessage(
                config.chatid,
                "[Dota 2] Игра началась! (после горна)"
            );
        }
    });
    client.on("hero:name", (heroname) => {
        console.log(heroname);
        if (_client != undefined) {
            _client.write(`hn:${heroname}`);
            _client.pipe(client);
        }
    });
});
