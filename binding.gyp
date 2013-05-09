{
    "targets": [
        {
            "target_name": "notification",
            "sources": [
              "src/node/notification.cc"
            ],
            "conditions": [
                ["OS==\"win\"", {
                    # TO BE COMPLETED
                }],
                ["OS==\"mac\"", {
                    "include_dirs": [
                        "src/headers/"
                    ],
                    "xcode_settings": {
                        "OTHER_CFLAGS": [
                            "-ObjC++"
                        ]
                    },
                    "link_settings" : {
                        "libraries" : [
                            "-framework Cocoa"
                        ]
                    },
                    "sources": [
                        "src/mac/FakeBundle.m",
                        "src/mac/notification.cpp"
                    ]
                }, {
                    # TO BE COMPLETED
                }]
            ]
        }
    ]
}