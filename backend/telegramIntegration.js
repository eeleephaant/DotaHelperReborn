const { Telegraf } = require('telegraf');
const { exec } = require("child_process");
const fs = require('fs');
const { setTimeout } = require('timers');
require('dotenv').config();

let bot = new Telegraf(process.env.BOT_TOKEN);

var config = require('./config.json');
module.exports.bot = bot;

bot.start((ctx) => {
    config.chatid = ctx.message.chat.id;
    fs.writeFileSync('config.json', JSON.stringify(config));
    ctx.reply(`✅Авторизован. chatid: ${config.chatid}`);
})

bot.on('message', async (ctx) => {
    try {
        console.log(ctx.message);
        if (ctx.message.from.username === 'qoklas') {

            if (ctx.message.text === '/screenshot') {
                fs.unlink('./temp/1.jpg', err => {
                    if (err) console.log('Нечего удалять!');
                    console.log('Файл удалён!');
                });
                var photoMess;
                exec("scrot ./temp/1.jpg", async (error, stdout, stderr) => {
                    photoMess = await ctx.replyWithPhoto({ source: fs.createReadStream('./temp/1.jpg') });
                    setTimeout(() => {
                        ctx.deleteMessage(photoMess.message_id);
                        ctx.deleteMessage(ctx.message.reply_to_message);
                    }, 15000);
                })
            }

            if (ctx.message.text === '/uptime') {
                exec("uptime", async (error, stdout, stderr) => {
                    ctx.replyWithMarkdown(`👉_${stdout}_👈`);
                })
            }

            if (ctx.message.text === '/poweroff') {
                exec("sudo poweroff", (error, stdout, stderr) => {
                    ctx.replyWithMarkdown(`✅**${stdout}**`);
                })
            }

            if (ctx.message.text === '') {
                
            }
        }
    }
    catch (err) { console.log(err); }
})

bot.launch();

process.once('SIGINT', () => bot.stop('SIGINT'));
process.once('SIGTERM', () => bot.stop('SIGTERM'));