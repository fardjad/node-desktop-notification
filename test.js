var assert = require('assert'),
    notification;

assert.doesNotThrow(function () {
    'use strict';
    notification = require('./lib/notification.js');
});

assert.equal(!!notification.show('Testing...'), true);