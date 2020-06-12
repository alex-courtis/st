typedef struct {
	char *name;
	unsigned int enabled;
	char *colorname[16];
	unsigned int defaultfg;
	unsigned int defaultbg;
	unsigned int defaultcs;
	unsigned int defaultrcs;
} Theme;

static unsigned int theme;
static unsigned int rtheme;

static Theme themes[] = {
	{
		.name = "default",
		.enabled = 1,
		.colorname = {
			"black",
			"red3",
			"green3",
			"yellow3",
			"blue2",
			"magenta3",
			"cyan3",
			"gray90",
			"gray50",
			"red",
			"green",
			"yellow",
			"#5c5cff",
			"magenta",
			"cyan",
			"white",
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 15,
		.defaultrcs = 0,
	},
	{
		.name = "base16-3024", .enabled = 0,
		.colorname = {
			"#090300", /* base00 */
			"#db2d20", /* base08 */
			"#01a252", /* base0B */
			"#fded02", /* base0A */
			"#01a0e4", /* base0D */
			"#a16a94", /* base0E */
			"#b5e4f4", /* base0C */
			"#a5a2a2", /* base05 */
			"#5c5855", /* base03 */
			"#e8bbd0", /* base09 */
			"#3a3432", /* base01 */
			"#4a4543", /* base02 */
			"#807d7c", /* base04 */
			"#d6d5d4", /* base06 */
			"#cdab53", /* base0F */
			"#f7f7f7", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-apathy", .enabled = 0,
		.colorname = {
			"#031A16", /* base00 */
			"#3E9688", /* base08 */
			"#883E96", /* base0B */
			"#3E4C96", /* base0A */
			"#96883E", /* base0D */
			"#4C963E", /* base0E */
			"#963E4C", /* base0C */
			"#81B5AC", /* base05 */
			"#2B685E", /* base03 */
			"#3E7996", /* base09 */
			"#0B342D", /* base01 */
			"#184E45", /* base02 */
			"#5F9C92", /* base04 */
			"#A7CEC8", /* base06 */
			"#3E965B", /* base0F */
			"#D2E7E4", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-ashes", .enabled = 0,
		.colorname = {
			"#1C2023", /* base00 */
			"#C7AE95", /* base08 */
			"#95C7AE", /* base0B */
			"#AEC795", /* base0A */
			"#AE95C7", /* base0D */
			"#C795AE", /* base0E */
			"#95AEC7", /* base0C */
			"#C7CCD1", /* base05 */
			"#747C84", /* base03 */
			"#C7C795", /* base09 */
			"#393F45", /* base01 */
			"#565E65", /* base02 */
			"#ADB3BA", /* base04 */
			"#DFE2E5", /* base06 */
			"#C79595", /* base0F */
			"#F3F4F5", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-cave", .enabled = 0,
		.colorname = {
			"#19171c", /* base00 */
			"#be4678", /* base08 */
			"#2a9292", /* base0B */
			"#a06e3b", /* base0A */
			"#576ddb", /* base0D */
			"#955ae7", /* base0E */
			"#398bc6", /* base0C */
			"#8b8792", /* base05 */
			"#655f6d", /* base03 */
			"#aa573c", /* base09 */
			"#26232a", /* base01 */
			"#585260", /* base02 */
			"#7e7887", /* base04 */
			"#e2dfe7", /* base06 */
			"#bf40bf", /* base0F */
			"#efecf4", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-cave-light", .enabled = 0,
		.colorname = {
			"#efecf4", /* base00 */
			"#be4678", /* base08 */
			"#2a9292", /* base0B */
			"#a06e3b", /* base0A */
			"#576ddb", /* base0D */
			"#955ae7", /* base0E */
			"#398bc6", /* base0C */
			"#585260", /* base05 */
			"#7e7887", /* base03 */
			"#aa573c", /* base09 */
			"#e2dfe7", /* base01 */
			"#8b8792", /* base02 */
			"#655f6d", /* base04 */
			"#26232a", /* base06 */
			"#bf40bf", /* base0F */
			"#19171c", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-dune", .enabled = 0,
		.colorname = {
			"#20201d", /* base00 */
			"#d73737", /* base08 */
			"#60ac39", /* base0B */
			"#ae9513", /* base0A */
			"#6684e1", /* base0D */
			"#b854d4", /* base0E */
			"#1fad83", /* base0C */
			"#a6a28c", /* base05 */
			"#7d7a68", /* base03 */
			"#b65611", /* base09 */
			"#292824", /* base01 */
			"#6e6b5e", /* base02 */
			"#999580", /* base04 */
			"#e8e4cf", /* base06 */
			"#d43552", /* base0F */
			"#fefbec", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-dune-light", .enabled = 0,
		.colorname = {
			"#fefbec", /* base00 */
			"#d73737", /* base08 */
			"#60ac39", /* base0B */
			"#ae9513", /* base0A */
			"#6684e1", /* base0D */
			"#b854d4", /* base0E */
			"#1fad83", /* base0C */
			"#6e6b5e", /* base05 */
			"#999580", /* base03 */
			"#b65611", /* base09 */
			"#e8e4cf", /* base01 */
			"#a6a28c", /* base02 */
			"#7d7a68", /* base04 */
			"#292824", /* base06 */
			"#d43552", /* base0F */
			"#20201d", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-estuary", .enabled = 0,
		.colorname = {
			"#22221b", /* base00 */
			"#ba6236", /* base08 */
			"#7d9726", /* base0B */
			"#a5980d", /* base0A */
			"#36a166", /* base0D */
			"#5f9182", /* base0E */
			"#5b9d48", /* base0C */
			"#929181", /* base05 */
			"#6c6b5a", /* base03 */
			"#ae7313", /* base09 */
			"#302f27", /* base01 */
			"#5f5e4e", /* base02 */
			"#878573", /* base04 */
			"#e7e6df", /* base06 */
			"#9d6c7c", /* base0F */
			"#f4f3ec", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-estuary-light", .enabled = 0,
		.colorname = {
			"#f4f3ec", /* base00 */
			"#ba6236", /* base08 */
			"#7d9726", /* base0B */
			"#a5980d", /* base0A */
			"#36a166", /* base0D */
			"#5f9182", /* base0E */
			"#5b9d48", /* base0C */
			"#5f5e4e", /* base05 */
			"#878573", /* base03 */
			"#ae7313", /* base09 */
			"#e7e6df", /* base01 */
			"#929181", /* base02 */
			"#6c6b5a", /* base04 */
			"#302f27", /* base06 */
			"#9d6c7c", /* base0F */
			"#22221b", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-forest", .enabled = 0,
		.colorname = {
			"#1b1918", /* base00 */
			"#f22c40", /* base08 */
			"#7b9726", /* base0B */
			"#c38418", /* base0A */
			"#407ee7", /* base0D */
			"#6666ea", /* base0E */
			"#3d97b8", /* base0C */
			"#a8a19f", /* base05 */
			"#766e6b", /* base03 */
			"#df5320", /* base09 */
			"#2c2421", /* base01 */
			"#68615e", /* base02 */
			"#9c9491", /* base04 */
			"#e6e2e0", /* base06 */
			"#c33ff3", /* base0F */
			"#f1efee", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-forest-light", .enabled = 0,
		.colorname = {
			"#f1efee", /* base00 */
			"#f22c40", /* base08 */
			"#7b9726", /* base0B */
			"#c38418", /* base0A */
			"#407ee7", /* base0D */
			"#6666ea", /* base0E */
			"#3d97b8", /* base0C */
			"#68615e", /* base05 */
			"#9c9491", /* base03 */
			"#df5320", /* base09 */
			"#e6e2e0", /* base01 */
			"#a8a19f", /* base02 */
			"#766e6b", /* base04 */
			"#2c2421", /* base06 */
			"#c33ff3", /* base0F */
			"#1b1918", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-heath", .enabled = 0,
		.colorname = {
			"#1b181b", /* base00 */
			"#ca402b", /* base08 */
			"#918b3b", /* base0B */
			"#bb8a35", /* base0A */
			"#516aec", /* base0D */
			"#7b59c0", /* base0E */
			"#159393", /* base0C */
			"#ab9bab", /* base05 */
			"#776977", /* base03 */
			"#a65926", /* base09 */
			"#292329", /* base01 */
			"#695d69", /* base02 */
			"#9e8f9e", /* base04 */
			"#d8cad8", /* base06 */
			"#cc33cc", /* base0F */
			"#f7f3f7", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-heath-light", .enabled = 0,
		.colorname = {
			"#f7f3f7", /* base00 */
			"#ca402b", /* base08 */
			"#918b3b", /* base0B */
			"#bb8a35", /* base0A */
			"#516aec", /* base0D */
			"#7b59c0", /* base0E */
			"#159393", /* base0C */
			"#695d69", /* base05 */
			"#9e8f9e", /* base03 */
			"#a65926", /* base09 */
			"#d8cad8", /* base01 */
			"#ab9bab", /* base02 */
			"#776977", /* base04 */
			"#292329", /* base06 */
			"#cc33cc", /* base0F */
			"#1b181b", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-lakeside", .enabled = 0,
		.colorname = {
			"#161b1d", /* base00 */
			"#d22d72", /* base08 */
			"#568c3b", /* base0B */
			"#8a8a0f", /* base0A */
			"#257fad", /* base0D */
			"#6b6bb8", /* base0E */
			"#2d8f6f", /* base0C */
			"#7ea2b4", /* base05 */
			"#5a7b8c", /* base03 */
			"#935c25", /* base09 */
			"#1f292e", /* base01 */
			"#516d7b", /* base02 */
			"#7195a8", /* base04 */
			"#c1e4f6", /* base06 */
			"#b72dd2", /* base0F */
			"#ebf8ff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-lakeside-light", .enabled = 0,
		.colorname = {
			"#ebf8ff", /* base00 */
			"#d22d72", /* base08 */
			"#568c3b", /* base0B */
			"#8a8a0f", /* base0A */
			"#257fad", /* base0D */
			"#6b6bb8", /* base0E */
			"#2d8f6f", /* base0C */
			"#516d7b", /* base05 */
			"#7195a8", /* base03 */
			"#935c25", /* base09 */
			"#c1e4f6", /* base01 */
			"#7ea2b4", /* base02 */
			"#5a7b8c", /* base04 */
			"#1f292e", /* base06 */
			"#b72dd2", /* base0F */
			"#161b1d", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-plateau", .enabled = 0,
		.colorname = {
			"#1b1818", /* base00 */
			"#ca4949", /* base08 */
			"#4b8b8b", /* base0B */
			"#a06e3b", /* base0A */
			"#7272ca", /* base0D */
			"#8464c4", /* base0E */
			"#5485b6", /* base0C */
			"#8a8585", /* base05 */
			"#655d5d", /* base03 */
			"#b45a3c", /* base09 */
			"#292424", /* base01 */
			"#585050", /* base02 */
			"#7e7777", /* base04 */
			"#e7dfdf", /* base06 */
			"#bd5187", /* base0F */
			"#f4ecec", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-plateau-light", .enabled = 0,
		.colorname = {
			"#f4ecec", /* base00 */
			"#ca4949", /* base08 */
			"#4b8b8b", /* base0B */
			"#a06e3b", /* base0A */
			"#7272ca", /* base0D */
			"#8464c4", /* base0E */
			"#5485b6", /* base0C */
			"#585050", /* base05 */
			"#7e7777", /* base03 */
			"#b45a3c", /* base09 */
			"#e7dfdf", /* base01 */
			"#8a8585", /* base02 */
			"#655d5d", /* base04 */
			"#292424", /* base06 */
			"#bd5187", /* base0F */
			"#1b1818", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-savanna", .enabled = 0,
		.colorname = {
			"#171c19", /* base00 */
			"#b16139", /* base08 */
			"#489963", /* base0B */
			"#a07e3b", /* base0A */
			"#478c90", /* base0D */
			"#55859b", /* base0E */
			"#1c9aa0", /* base0C */
			"#87928a", /* base05 */
			"#5f6d64", /* base03 */
			"#9f713c", /* base09 */
			"#232a25", /* base01 */
			"#526057", /* base02 */
			"#78877d", /* base04 */
			"#dfe7e2", /* base06 */
			"#867469", /* base0F */
			"#ecf4ee", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-savanna-light", .enabled = 0,
		.colorname = {
			"#ecf4ee", /* base00 */
			"#b16139", /* base08 */
			"#489963", /* base0B */
			"#a07e3b", /* base0A */
			"#478c90", /* base0D */
			"#55859b", /* base0E */
			"#1c9aa0", /* base0C */
			"#526057", /* base05 */
			"#78877d", /* base03 */
			"#9f713c", /* base09 */
			"#dfe7e2", /* base01 */
			"#87928a", /* base02 */
			"#5f6d64", /* base04 */
			"#232a25", /* base06 */
			"#867469", /* base0F */
			"#171c19", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-seaside", .enabled = 0,
		.colorname = {
			"#131513", /* base00 */
			"#e6193c", /* base08 */
			"#29a329", /* base0B */
			"#98981b", /* base0A */
			"#3d62f5", /* base0D */
			"#ad2bee", /* base0E */
			"#1999b3", /* base0C */
			"#8ca68c", /* base05 */
			"#687d68", /* base03 */
			"#87711d", /* base09 */
			"#242924", /* base01 */
			"#5e6e5e", /* base02 */
			"#809980", /* base04 */
			"#cfe8cf", /* base06 */
			"#e619c3", /* base0F */
			"#f4fbf4", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-seaside-light", .enabled = 0,
		.colorname = {
			"#f4fbf4", /* base00 */
			"#e6193c", /* base08 */
			"#29a329", /* base0B */
			"#98981b", /* base0A */
			"#3d62f5", /* base0D */
			"#ad2bee", /* base0E */
			"#1999b3", /* base0C */
			"#5e6e5e", /* base05 */
			"#809980", /* base03 */
			"#87711d", /* base09 */
			"#cfe8cf", /* base01 */
			"#8ca68c", /* base02 */
			"#687d68", /* base04 */
			"#242924", /* base06 */
			"#e619c3", /* base0F */
			"#131513", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-sulphurpool", .enabled = 0,
		.colorname = {
			"#202746", /* base00 */
			"#c94922", /* base08 */
			"#ac9739", /* base0B */
			"#c08b30", /* base0A */
			"#3d8fd1", /* base0D */
			"#6679cc", /* base0E */
			"#22a2c9", /* base0C */
			"#979db4", /* base05 */
			"#6b7394", /* base03 */
			"#c76b29", /* base09 */
			"#293256", /* base01 */
			"#5e6687", /* base02 */
			"#898ea4", /* base04 */
			"#dfe2f1", /* base06 */
			"#9c637a", /* base0F */
			"#f5f7ff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atelier-sulphurpool-light", .enabled = 0,
		.colorname = {
			"#f5f7ff", /* base00 */
			"#c94922", /* base08 */
			"#ac9739", /* base0B */
			"#c08b30", /* base0A */
			"#3d8fd1", /* base0D */
			"#6679cc", /* base0E */
			"#22a2c9", /* base0C */
			"#5e6687", /* base05 */
			"#898ea4", /* base03 */
			"#c76b29", /* base09 */
			"#dfe2f1", /* base01 */
			"#979db4", /* base02 */
			"#6b7394", /* base04 */
			"#293256", /* base06 */
			"#9c637a", /* base0F */
			"#202746", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-atlas", .enabled = 0,
		.colorname = {
			"#002635", /* base00 */
			"#ff5a67", /* base08 */
			"#7fc06e", /* base0B */
			"#ffcc1b", /* base0A */
			"#5dd7b9", /* base0D */
			"#9a70a4", /* base0E */
			"#14747e", /* base0C */
			"#a1a19a", /* base05 */
			"#6C8B91", /* base03 */
			"#f08e48", /* base09 */
			"#00384d", /* base01 */
			"#517F8D", /* base02 */
			"#869696", /* base04 */
			"#e6e6dc", /* base06 */
			"#c43060", /* base0F */
			"#fafaf8", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-bespin", .enabled = 0,
		.colorname = {
			"#28211c", /* base00 */
			"#cf6a4c", /* base08 */
			"#54be0d", /* base0B */
			"#f9ee98", /* base0A */
			"#5ea6ea", /* base0D */
			"#9b859d", /* base0E */
			"#afc4db", /* base0C */
			"#8a8986", /* base05 */
			"#666666", /* base03 */
			"#cf7d34", /* base09 */
			"#36312e", /* base01 */
			"#5e5d5c", /* base02 */
			"#797977", /* base04 */
			"#9d9b97", /* base06 */
			"#937121", /* base0F */
			"#baae9e", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-black-metal-bathory", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#5f8787", /* base08 */
			"#fbcb97", /* base0B */
			"#e78a53", /* base0A */
			"#888888", /* base0D */
			"#999999", /* base0E */
			"#aaaaaa", /* base0C */
			"#c1c1c1", /* base05 */
			"#333333", /* base03 */
			"#aaaaaa", /* base09 */
			"#121212", /* base01 */
			"#222222", /* base02 */
			"#999999", /* base04 */
			"#999999", /* base06 */
			"#444444", /* base0F */
			"#c1c1c1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-black-metal-burzum", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#5f8787", /* base08 */
			"#ddeecc", /* base0B */
			"#99bbaa", /* base0A */
			"#888888", /* base0D */
			"#999999", /* base0E */
			"#aaaaaa", /* base0C */
			"#c1c1c1", /* base05 */
			"#333333", /* base03 */
			"#aaaaaa", /* base09 */
			"#121212", /* base01 */
			"#222222", /* base02 */
			"#999999", /* base04 */
			"#999999", /* base06 */
			"#444444", /* base0F */
			"#c1c1c1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-black-metal-dark-funeral", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#5f8787", /* base08 */
			"#d0dfee", /* base0B */
			"#5f81a5", /* base0A */
			"#888888", /* base0D */
			"#999999", /* base0E */
			"#aaaaaa", /* base0C */
			"#c1c1c1", /* base05 */
			"#333333", /* base03 */
			"#aaaaaa", /* base09 */
			"#121212", /* base01 */
			"#222222", /* base02 */
			"#999999", /* base04 */
			"#999999", /* base06 */
			"#444444", /* base0F */
			"#c1c1c1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-black-metal-gorgoroth", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#5f8787", /* base08 */
			"#9b8d7f", /* base0B */
			"#8c7f70", /* base0A */
			"#888888", /* base0D */
			"#999999", /* base0E */
			"#aaaaaa", /* base0C */
			"#c1c1c1", /* base05 */
			"#333333", /* base03 */
			"#aaaaaa", /* base09 */
			"#121212", /* base01 */
			"#222222", /* base02 */
			"#999999", /* base04 */
			"#999999", /* base06 */
			"#444444", /* base0F */
			"#c1c1c1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-black-metal", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#5f8787", /* base08 */
			"#dd9999", /* base0B */
			"#a06666", /* base0A */
			"#888888", /* base0D */
			"#999999", /* base0E */
			"#aaaaaa", /* base0C */
			"#c1c1c1", /* base05 */
			"#333333", /* base03 */
			"#aaaaaa", /* base09 */
			"#121212", /* base01 */
			"#222222", /* base02 */
			"#999999", /* base04 */
			"#999999", /* base06 */
			"#444444", /* base0F */
			"#c1c1c1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-black-metal-immortal", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#5f8787", /* base08 */
			"#7799bb", /* base0B */
			"#556677", /* base0A */
			"#888888", /* base0D */
			"#999999", /* base0E */
			"#aaaaaa", /* base0C */
			"#c1c1c1", /* base05 */
			"#333333", /* base03 */
			"#aaaaaa", /* base09 */
			"#121212", /* base01 */
			"#222222", /* base02 */
			"#999999", /* base04 */
			"#999999", /* base06 */
			"#444444", /* base0F */
			"#c1c1c1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-black-metal-khold", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#5f8787", /* base08 */
			"#eceee3", /* base0B */
			"#974b46", /* base0A */
			"#888888", /* base0D */
			"#999999", /* base0E */
			"#aaaaaa", /* base0C */
			"#c1c1c1", /* base05 */
			"#333333", /* base03 */
			"#aaaaaa", /* base09 */
			"#121212", /* base01 */
			"#222222", /* base02 */
			"#999999", /* base04 */
			"#999999", /* base06 */
			"#444444", /* base0F */
			"#c1c1c1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-black-metal-marduk", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#5f8787", /* base08 */
			"#a5aaa7", /* base0B */
			"#626b67", /* base0A */
			"#888888", /* base0D */
			"#999999", /* base0E */
			"#aaaaaa", /* base0C */
			"#c1c1c1", /* base05 */
			"#333333", /* base03 */
			"#aaaaaa", /* base09 */
			"#121212", /* base01 */
			"#222222", /* base02 */
			"#999999", /* base04 */
			"#999999", /* base06 */
			"#444444", /* base0F */
			"#c1c1c1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-black-metal-mayhem", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#5f8787", /* base08 */
			"#f3ecd4", /* base0B */
			"#eecc6c", /* base0A */
			"#888888", /* base0D */
			"#999999", /* base0E */
			"#aaaaaa", /* base0C */
			"#c1c1c1", /* base05 */
			"#333333", /* base03 */
			"#aaaaaa", /* base09 */
			"#121212", /* base01 */
			"#222222", /* base02 */
			"#999999", /* base04 */
			"#999999", /* base06 */
			"#444444", /* base0F */
			"#c1c1c1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-black-metal-nile", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#5f8787", /* base08 */
			"#aa9988", /* base0B */
			"#777755", /* base0A */
			"#888888", /* base0D */
			"#999999", /* base0E */
			"#aaaaaa", /* base0C */
			"#c1c1c1", /* base05 */
			"#333333", /* base03 */
			"#aaaaaa", /* base09 */
			"#121212", /* base01 */
			"#222222", /* base02 */
			"#999999", /* base04 */
			"#999999", /* base06 */
			"#444444", /* base0F */
			"#c1c1c1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-black-metal-venom", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#5f8787", /* base08 */
			"#f8f7f2", /* base0B */
			"#79241f", /* base0A */
			"#888888", /* base0D */
			"#999999", /* base0E */
			"#aaaaaa", /* base0C */
			"#c1c1c1", /* base05 */
			"#333333", /* base03 */
			"#aaaaaa", /* base09 */
			"#121212", /* base01 */
			"#222222", /* base02 */
			"#999999", /* base04 */
			"#999999", /* base06 */
			"#444444", /* base0F */
			"#c1c1c1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-brewer", .enabled = 1,
		.colorname = {
			"#0c0d0e", /* base00 */
			"#e31a1c", /* base08 */
			"#31a354", /* base0B */
			"#dca060", /* base0A */
			"#3182bd", /* base0D */
			"#756bb1", /* base0E */
			"#80b1d3", /* base0C */
			"#b7b8b9", /* base05 */
			"#737475", /* base03 */
			"#e6550d", /* base09 */
			"#2e2f30", /* base01 */
			"#515253", /* base02 */
			"#959697", /* base04 */
			"#dadbdc", /* base06 */
			"#b15928", /* base0F */
			"#fcfdfe", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-bright", .enabled = 1,
		.colorname = {
			"#000000", /* base00 */
			"#fb0120", /* base08 */
			"#a1c659", /* base0B */
			"#fda331", /* base0A */
			"#6fb3d2", /* base0D */
			"#d381c3", /* base0E */
			"#76c7b7", /* base0C */
			"#e0e0e0", /* base05 */
			"#b0b0b0", /* base03 */
			"#fc6d24", /* base09 */
			"#303030", /* base01 */
			"#505050", /* base02 */
			"#d0d0d0", /* base04 */
			"#f5f5f5", /* base06 */
			"#be643c", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-brogrammer", .enabled = 0,
		.colorname = {
			"#1f1f1f", /* base00 */
			"#d6dbe5", /* base08 */
			"#f3bd09", /* base0B */
			"#1dd361", /* base0A */
			"#5350b9", /* base0D */
			"#0f7ddb", /* base0E */
			"#1081d6", /* base0C */
			"#4e5ab7", /* base05 */
			"#ecba0f", /* base03 */
			"#de352e", /* base09 */
			"#f81118", /* base01 */
			"#2dc55e", /* base02 */
			"#2a84d2", /* base04 */
			"#1081d6", /* base06 */
			"#ffffff", /* base0F */
			"#d6dbe5", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-brushtrees-dark", .enabled = 0,
		.colorname = {
			"#485867", /* base00 */
			"#b38686", /* base08 */
			"#87b386", /* base0B */
			"#aab386", /* base0A */
			"#868cb3", /* base0D */
			"#b386b2", /* base0E */
			"#86b3b3", /* base0C */
			"#B0C5C8", /* base05 */
			"#8299A1", /* base03 */
			"#d8bba2", /* base09 */
			"#5A6D7A", /* base01 */
			"#6D828E", /* base02 */
			"#98AFB5", /* base04 */
			"#C9DBDC", /* base06 */
			"#b39f9f", /* base0F */
			"#E3EFEF", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-brushtrees", .enabled = 0,
		.colorname = {
			"#E3EFEF", /* base00 */
			"#b38686", /* base08 */
			"#87b386", /* base0B */
			"#aab386", /* base0A */
			"#868cb3", /* base0D */
			"#b386b2", /* base0E */
			"#86b3b3", /* base0C */
			"#6D828E", /* base05 */
			"#98AFB5", /* base03 */
			"#d8bba2", /* base09 */
			"#C9DBDC", /* base01 */
			"#B0C5C8", /* base02 */
			"#8299A1", /* base04 */
			"#5A6D7A", /* base06 */
			"#b39f9f", /* base0F */
			"#485867", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-chalk", .enabled = 0,
		.colorname = {
			"#151515", /* base00 */
			"#fb9fb1", /* base08 */
			"#acc267", /* base0B */
			"#ddb26f", /* base0A */
			"#6fc2ef", /* base0D */
			"#e1a3ee", /* base0E */
			"#12cfc0", /* base0C */
			"#d0d0d0", /* base05 */
			"#505050", /* base03 */
			"#eda987", /* base09 */
			"#202020", /* base01 */
			"#303030", /* base02 */
			"#b0b0b0", /* base04 */
			"#e0e0e0", /* base06 */
			"#deaf8f", /* base0F */
			"#f5f5f5", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-circus", .enabled = 0,
		.colorname = {
			"#191919", /* base00 */
			"#dc657d", /* base08 */
			"#84b97c", /* base0B */
			"#c3ba63", /* base0A */
			"#639ee4", /* base0D */
			"#b888e2", /* base0E */
			"#4bb1a7", /* base0C */
			"#a7a7a7", /* base05 */
			"#5f5a60", /* base03 */
			"#4bb1a7", /* base09 */
			"#202020", /* base01 */
			"#303030", /* base02 */
			"#505050", /* base04 */
			"#808080", /* base06 */
			"#b888e2", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-classic-dark", .enabled = 0,
		.colorname = {
			"#151515", /* base00 */
			"#AC4142", /* base08 */
			"#90A959", /* base0B */
			"#F4BF75", /* base0A */
			"#6A9FB5", /* base0D */
			"#AA759F", /* base0E */
			"#75B5AA", /* base0C */
			"#D0D0D0", /* base05 */
			"#505050", /* base03 */
			"#D28445", /* base09 */
			"#202020", /* base01 */
			"#303030", /* base02 */
			"#B0B0B0", /* base04 */
			"#E0E0E0", /* base06 */
			"#8F5536", /* base0F */
			"#F5F5F5", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-classic-light", .enabled = 0,
		.colorname = {
			"#F5F5F5", /* base00 */
			"#AC4142", /* base08 */
			"#90A959", /* base0B */
			"#F4BF75", /* base0A */
			"#6A9FB5", /* base0D */
			"#AA759F", /* base0E */
			"#75B5AA", /* base0C */
			"#303030", /* base05 */
			"#B0B0B0", /* base03 */
			"#D28445", /* base09 */
			"#E0E0E0", /* base01 */
			"#D0D0D0", /* base02 */
			"#505050", /* base04 */
			"#202020", /* base06 */
			"#8F5536", /* base0F */
			"#151515", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-codeschool", .enabled = 0,
		.colorname = {
			"#232c31", /* base00 */
			"#2a5491", /* base08 */
			"#237986", /* base0B */
			"#a03b1e", /* base0A */
			"#484d79", /* base0D */
			"#c59820", /* base0E */
			"#b02f30", /* base0C */
			"#9ea7a6", /* base05 */
			"#3f4944", /* base03 */
			"#43820d", /* base09 */
			"#1c3657", /* base01 */
			"#2a343a", /* base02 */
			"#84898c", /* base04 */
			"#a7cfa3", /* base06 */
			"#c98344", /* base0F */
			"#b5d8f6", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-cupcake", .enabled = 0,
		.colorname = {
			"#fbf1f2", /* base00 */
			"#D57E85", /* base08 */
			"#A3B367", /* base0B */
			"#DCB16C", /* base0A */
			"#7297B9", /* base0D */
			"#BB99B4", /* base0E */
			"#69A9A7", /* base0C */
			"#8b8198", /* base05 */
			"#bfb9c6", /* base03 */
			"#EBB790", /* base09 */
			"#f2f1f4", /* base01 */
			"#d8d5dd", /* base02 */
			"#a59daf", /* base04 */
			"#72677E", /* base06 */
			"#BAA58C", /* base0F */
			"#585062", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-cupertino", .enabled = 0,
		.colorname = {
			"#ffffff", /* base00 */
			"#c41a15", /* base08 */
			"#007400", /* base0B */
			"#826b28", /* base0A */
			"#0000ff", /* base0D */
			"#a90d91", /* base0E */
			"#318495", /* base0C */
			"#404040", /* base05 */
			"#808080", /* base03 */
			"#eb8500", /* base09 */
			"#c0c0c0", /* base01 */
			"#c0c0c0", /* base02 */
			"#808080", /* base04 */
			"#404040", /* base06 */
			"#826b28", /* base0F */
			"#5e5e5e", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-darkmoss", .enabled = 0,
		.colorname = {
			"#171e1f", /* base00 */
			"#ff4658", /* base08 */
			"#499180", /* base0B */
			"#fdb11f", /* base0A */
			"#498091", /* base0D */
			"#9bc0c8", /* base0E */
			"#66d9ef", /* base0C */
			"#c7c7a5", /* base05 */
			"#555e5f", /* base03 */
			"#e6db74", /* base09 */
			"#252c2d", /* base01 */
			"#373c3d", /* base02 */
			"#818f80", /* base04 */
			"#e3e3c8", /* base06 */
			"#d27b53", /* base0F */
			"#e1eaef", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-darktooth", .enabled = 0,
		.colorname = {
			"#1D2021", /* base00 */
			"#FB543F", /* base08 */
			"#95C085", /* base0B */
			"#FAC03B", /* base0A */
			"#0D6678", /* base0D */
			"#8F4673", /* base0E */
			"#8BA59B", /* base0C */
			"#A89984", /* base05 */
			"#665C54", /* base03 */
			"#FE8625", /* base09 */
			"#32302F", /* base01 */
			"#504945", /* base02 */
			"#928374", /* base04 */
			"#D5C4A1", /* base06 */
			"#A87322", /* base0F */
			"#FDF4C1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-darkviolet", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#a82ee6", /* base08 */
			"#4595e6", /* base0B */
			"#f29df2", /* base0A */
			"#4136d9", /* base0D */
			"#7e5ce6", /* base0E */
			"#40dfff", /* base0C */
			"#b08ae6", /* base05 */
			"#593380", /* base03 */
			"#bb66cc", /* base09 */
			"#231a40", /* base01 */
			"#432d59", /* base02 */
			"#00ff00", /* base04 */
			"#9045e6", /* base06 */
			"#a886bf", /* base0F */
			"#a366ff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-decaf", .enabled = 0,
		.colorname = {
			"#2d2d2d", /* base00 */
			"#ff7f7b", /* base08 */
			"#beda78", /* base0B */
			"#ffd67c", /* base0A */
			"#90bee1", /* base0D */
			"#efb3f7", /* base0E */
			"#bed6ff", /* base0C */
			"#cccccc", /* base05 */
			"#777777", /* base03 */
			"#ffbf70", /* base09 */
			"#393939", /* base01 */
			"#515151", /* base02 */
			"#b4b7b4", /* base04 */
			"#e0e0e0", /* base06 */
			"#ff93b3", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-default-dark", .enabled = 0,
		.colorname = {
			"#181818", /* base00 */
			"#ab4642", /* base08 */
			"#a1b56c", /* base0B */
			"#f7ca88", /* base0A */
			"#7cafc2", /* base0D */
			"#ba8baf", /* base0E */
			"#86c1b9", /* base0C */
			"#d8d8d8", /* base05 */
			"#585858", /* base03 */
			"#dc9656", /* base09 */
			"#282828", /* base01 */
			"#383838", /* base02 */
			"#b8b8b8", /* base04 */
			"#e8e8e8", /* base06 */
			"#a16946", /* base0F */
			"#f8f8f8", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-default-light", .enabled = 0,
		.colorname = {
			"#f8f8f8", /* base00 */
			"#ab4642", /* base08 */
			"#a1b56c", /* base0B */
			"#f7ca88", /* base0A */
			"#7cafc2", /* base0D */
			"#ba8baf", /* base0E */
			"#86c1b9", /* base0C */
			"#383838", /* base05 */
			"#b8b8b8", /* base03 */
			"#dc9656", /* base09 */
			"#e8e8e8", /* base01 */
			"#d8d8d8", /* base02 */
			"#585858", /* base04 */
			"#282828", /* base06 */
			"#a16946", /* base0F */
			"#181818", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-dirtysea", .enabled = 0,
		.colorname = {
			"#e0e0e0", /* base00 */
			"#000090", /* base08 */
			"#730073", /* base0B */
			"#006565", /* base0A */
			"#007300", /* base0D */
			"#840000", /* base0E */
			"#755B00", /* base0C */
			"#000000", /* base05 */
			"#707070", /* base03 */
			"#006565", /* base09 */
			"#d0d0d0", /* base01 */
			"#c0c0c0", /* base02 */
			"#202020", /* base04 */
			"#f8f8f8", /* base06 */
			"#755B00", /* base0F */
			"#c4d9c4", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-dracula", .enabled = 0,
		.colorname = {
			"#282936", /* base00 */
			"#ea51b2", /* base08 */
			"#ebff87", /* base0B */
			"#00f769", /* base0A */
			"#62d6e8", /* base0D */
			"#b45bcf", /* base0E */
			"#a1efe4", /* base0C */
			"#e9e9f4", /* base05 */
			"#626483", /* base03 */
			"#b45bcf", /* base09 */
			"#3a3c4e", /* base01 */
			"#4d4f68", /* base02 */
			"#62d6e8", /* base04 */
			"#f1f2f8", /* base06 */
			"#00f769", /* base0F */
			"#f7f7fb", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-edge-dark", .enabled = 0,
		.colorname = {
			"#262729", /* base00 */
			"#e77171", /* base08 */
			"#a1bf78", /* base0B */
			"#dbb774", /* base0A */
			"#73b3e7", /* base0D */
			"#d390e7", /* base0E */
			"#5ebaa5", /* base0C */
			"#b7bec9", /* base05 */
			"#3e4249", /* base03 */
			"#e77171", /* base09 */
			"#88909f", /* base01 */
			"#b7bec9", /* base02 */
			"#73b3e7", /* base04 */
			"#d390e7", /* base06 */
			"#5ebaa5", /* base0F */
			"#3e4249", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-edge-light", .enabled = 0,
		.colorname = {
			"#fafafa", /* base00 */
			"#db7070", /* base08 */
			"#7c9f4b", /* base0B */
			"#d69822", /* base0A */
			"#6587bf", /* base0D */
			"#b870ce", /* base0E */
			"#509c93", /* base0C */
			"#5e646f", /* base05 */
			"#5e646f", /* base03 */
			"#db7070", /* base09 */
			"#7c9f4b", /* base01 */
			"#d69822", /* base02 */
			"#6587bf", /* base04 */
			"#b870ce", /* base06 */
			"#509c93", /* base0F */
			"#5e646f", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-eighties", .enabled = 0,
		.colorname = {
			"#2d2d2d", /* base00 */
			"#f2777a", /* base08 */
			"#99cc99", /* base0B */
			"#ffcc66", /* base0A */
			"#6699cc", /* base0D */
			"#cc99cc", /* base0E */
			"#66cccc", /* base0C */
			"#d3d0c8", /* base05 */
			"#747369", /* base03 */
			"#f99157", /* base09 */
			"#393939", /* base01 */
			"#515151", /* base02 */
			"#a09f93", /* base04 */
			"#e8e6df", /* base06 */
			"#d27b53", /* base0F */
			"#f2f0ec", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-embers", .enabled = 0,
		.colorname = {
			"#16130F", /* base00 */
			"#826D57", /* base08 */
			"#57826D", /* base0B */
			"#6D8257", /* base0A */
			"#6D5782", /* base0D */
			"#82576D", /* base0E */
			"#576D82", /* base0C */
			"#A39A90", /* base05 */
			"#5A5047", /* base03 */
			"#828257", /* base09 */
			"#2C2620", /* base01 */
			"#433B32", /* base02 */
			"#8A8075", /* base04 */
			"#BEB6AE", /* base06 */
			"#825757", /* base0F */
			"#DBD6D1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-equilibrium-dark", .enabled = 0,
		.colorname = {
			"#0c1118", /* base00 */
			"#f04339", /* base08 */
			"#7f8b00", /* base0B */
			"#bb8801", /* base0A */
			"#008dd1", /* base0D */
			"#6a7fd2", /* base0E */
			"#00948b", /* base0C */
			"#afaba2", /* base05 */
			"#7b776e", /* base03 */
			"#df5923", /* base09 */
			"#181c22", /* base01 */
			"#22262d", /* base02 */
			"#949088", /* base04 */
			"#cac6bd", /* base06 */
			"#e3488e", /* base0F */
			"#e7e2d9", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-equilibrium-gray-dark", .enabled = 0,
		.colorname = {
			"#111111", /* base00 */
			"#f04339", /* base08 */
			"#7f8b00", /* base0B */
			"#bb8801", /* base0A */
			"#008dd1", /* base0D */
			"#6a7fd2", /* base0E */
			"#00948b", /* base0C */
			"#ababab", /* base05 */
			"#777777", /* base03 */
			"#df5923", /* base09 */
			"#1b1b1b", /* base01 */
			"#262626", /* base02 */
			"#919191", /* base04 */
			"#c6c6c6", /* base06 */
			"#e3488e", /* base0F */
			"#e2e2e2", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-equilibrium-gray-light", .enabled = 0,
		.colorname = {
			"#f1f1f1", /* base00 */
			"#d02023", /* base08 */
			"#637200", /* base0B */
			"#9d6f00", /* base0A */
			"#0073b5", /* base0D */
			"#4e66b6", /* base0E */
			"#007a72", /* base0C */
			"#474747", /* base05 */
			"#777777", /* base03 */
			"#bf3e05", /* base09 */
			"#e2e2e2", /* base01 */
			"#d4d4d4", /* base02 */
			"#5e5e5e", /* base04 */
			"#303030", /* base06 */
			"#c42775", /* base0F */
			"#1b1b1b", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-equilibrium-light", .enabled = 0,
		.colorname = {
			"#f5f0e7", /* base00 */
			"#d02023", /* base08 */
			"#637200", /* base0B */
			"#9d6f00", /* base0A */
			"#0073b5", /* base0D */
			"#4e66b6", /* base0E */
			"#007a72", /* base0C */
			"#43474e", /* base05 */
			"#73777f", /* base03 */
			"#bf3e05", /* base09 */
			"#e7e2d9", /* base01 */
			"#d8d4cb", /* base02 */
			"#5a5f66", /* base04 */
			"#2c3138", /* base06 */
			"#c42775", /* base0F */
			"#181c22", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-espresso", .enabled = 0,
		.colorname = {
			"#2d2d2d", /* base00 */
			"#d25252", /* base08 */
			"#a5c261", /* base0B */
			"#ffc66d", /* base0A */
			"#6c99bb", /* base0D */
			"#d197d9", /* base0E */
			"#bed6ff", /* base0C */
			"#cccccc", /* base05 */
			"#777777", /* base03 */
			"#f9a959", /* base09 */
			"#393939", /* base01 */
			"#515151", /* base02 */
			"#b4b7b4", /* base04 */
			"#e0e0e0", /* base06 */
			"#f97394", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-eva-dim", .enabled = 0,
		.colorname = {
			"#2a3b4d", /* base00 */
			"#c4676c", /* base08 */
			"#5de561", /* base0B */
			"#cfd05d", /* base0A */
			"#1ae1dc", /* base0D */
			"#9c6cd3", /* base0E */
			"#4b8f77", /* base0C */
			"#9fa2a6", /* base05 */
			"#55799c", /* base03 */
			"#ff9966", /* base09 */
			"#3d566f", /* base01 */
			"#4b6988", /* base02 */
			"#7e90a3", /* base04 */
			"#d6d7d9", /* base06 */
			"#bb64a9", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-eva", .enabled = 0,
		.colorname = {
			"#2a3b4d", /* base00 */
			"#c4676c", /* base08 */
			"#66ff66", /* base0B */
			"#ffff66", /* base0A */
			"#15f4ee", /* base0D */
			"#9c6cd3", /* base0E */
			"#4b8f77", /* base0C */
			"#9fa2a6", /* base05 */
			"#55799c", /* base03 */
			"#ff9966", /* base09 */
			"#3d566f", /* base01 */
			"#4b6988", /* base02 */
			"#7e90a3", /* base04 */
			"#d6d7d9", /* base06 */
			"#bb64a9", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-flat", .enabled = 0,
		.colorname = {
			"#2C3E50", /* base00 */
			"#E74C3C", /* base08 */
			"#2ECC71", /* base0B */
			"#F1C40F", /* base0A */
			"#3498DB", /* base0D */
			"#9B59B6", /* base0E */
			"#1ABC9C", /* base0C */
			"#e0e0e0", /* base05 */
			"#95A5A6", /* base03 */
			"#E67E22", /* base09 */
			"#34495E", /* base01 */
			"#7F8C8D", /* base02 */
			"#BDC3C7", /* base04 */
			"#f5f5f5", /* base06 */
			"#be643c", /* base0F */
			"#ECF0F1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-framer", .enabled = 0,
		.colorname = {
			"#181818", /* base00 */
			"#FD886B", /* base08 */
			"#32CCDC", /* base0B */
			"#FECB6E", /* base0A */
			"#20BCFC", /* base0D */
			"#BA8CFC", /* base0E */
			"#ACDDFD", /* base0C */
			"#D0D0D0", /* base05 */
			"#747474", /* base03 */
			"#FC4769", /* base09 */
			"#151515", /* base01 */
			"#464646", /* base02 */
			"#B9B9B9", /* base04 */
			"#E8E8E8", /* base06 */
			"#B15F4A", /* base0F */
			"#EEEEEE", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-fruit-soda", .enabled = 0,
		.colorname = {
			"#f1ecf1", /* base00 */
			"#fe3e31", /* base08 */
			"#47f74c", /* base0B */
			"#f7e203", /* base0A */
			"#2931df", /* base0D */
			"#611fce", /* base0E */
			"#0f9cfd", /* base0C */
			"#515151", /* base05 */
			"#b5b4b6", /* base03 */
			"#fe6d08", /* base09 */
			"#e0dee0", /* base01 */
			"#d8d5d5", /* base02 */
			"#979598", /* base04 */
			"#474545", /* base06 */
			"#b16f40", /* base0F */
			"#2d2c2c", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-gigavolt", .enabled = 1,
		.colorname = {
			"#202126", /* base00 */
			"#ff661a", /* base08 */
			"#f2e6a9", /* base0B */
			"#ffdc2d", /* base0A */
			"#40bfff", /* base0D */
			"#ae94f9", /* base0E */
			"#fb6acb", /* base0C */
			"#e9e7e1", /* base05 */
			"#a1d2e6", /* base03 */
			"#19f988", /* base09 */
			"#2d303d", /* base01 */
			"#5a576e", /* base02 */
			"#cad3ff", /* base04 */
			"#eff0f9", /* base06 */
			"#6187ff", /* base0F */
			"#f2fbff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-github", .enabled = 0,
		.colorname = {
			"#ffffff", /* base00 */
			"#ed6a43", /* base08 */
			"#183691", /* base0B */
			"#795da3", /* base0A */
			"#795da3", /* base0D */
			"#a71d5d", /* base0E */
			"#183691", /* base0C */
			"#333333", /* base05 */
			"#969896", /* base03 */
			"#0086b3", /* base09 */
			"#f5f5f5", /* base01 */
			"#c8c8fa", /* base02 */
			"#e8e8e8", /* base04 */
			"#ffffff", /* base06 */
			"#333333", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-google-dark", .enabled = 0,
		.colorname = {
			"#1d1f21", /* base00 */
			"#CC342B", /* base08 */
			"#198844", /* base0B */
			"#FBA922", /* base0A */
			"#3971ED", /* base0D */
			"#A36AC7", /* base0E */
			"#3971ED", /* base0C */
			"#c5c8c6", /* base05 */
			"#969896", /* base03 */
			"#F96A38", /* base09 */
			"#282a2e", /* base01 */
			"#373b41", /* base02 */
			"#b4b7b4", /* base04 */
			"#e0e0e0", /* base06 */
			"#3971ED", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-google-light", .enabled = 0,
		.colorname = {
			"#ffffff", /* base00 */
			"#CC342B", /* base08 */
			"#198844", /* base0B */
			"#FBA922", /* base0A */
			"#3971ED", /* base0D */
			"#A36AC7", /* base0E */
			"#3971ED", /* base0C */
			"#373b41", /* base05 */
			"#b4b7b4", /* base03 */
			"#F96A38", /* base09 */
			"#e0e0e0", /* base01 */
			"#c5c8c6", /* base02 */
			"#969896", /* base04 */
			"#282a2e", /* base06 */
			"#3971ED", /* base0F */
			"#1d1f21", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-grayscale-dark", .enabled = 0,
		.colorname = {
			"#101010", /* base00 */
			"#7c7c7c", /* base08 */
			"#8e8e8e", /* base0B */
			"#a0a0a0", /* base0A */
			"#686868", /* base0D */
			"#747474", /* base0E */
			"#868686", /* base0C */
			"#b9b9b9", /* base05 */
			"#525252", /* base03 */
			"#999999", /* base09 */
			"#252525", /* base01 */
			"#464646", /* base02 */
			"#ababab", /* base04 */
			"#e3e3e3", /* base06 */
			"#5e5e5e", /* base0F */
			"#f7f7f7", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-grayscale-light", .enabled = 0,
		.colorname = {
			"#f7f7f7", /* base00 */
			"#7c7c7c", /* base08 */
			"#8e8e8e", /* base0B */
			"#a0a0a0", /* base0A */
			"#686868", /* base0D */
			"#747474", /* base0E */
			"#868686", /* base0C */
			"#464646", /* base05 */
			"#ababab", /* base03 */
			"#999999", /* base09 */
			"#e3e3e3", /* base01 */
			"#b9b9b9", /* base02 */
			"#525252", /* base04 */
			"#252525", /* base06 */
			"#5e5e5e", /* base0F */
			"#101010", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-greenscreen", .enabled = 0,
		.colorname = {
			"#001100", /* base00 */
			"#007700", /* base08 */
			"#00bb00", /* base0B */
			"#007700", /* base0A */
			"#009900", /* base0D */
			"#00bb00", /* base0E */
			"#005500", /* base0C */
			"#00bb00", /* base05 */
			"#007700", /* base03 */
			"#009900", /* base09 */
			"#003300", /* base01 */
			"#005500", /* base02 */
			"#009900", /* base04 */
			"#00dd00", /* base06 */
			"#005500", /* base0F */
			"#00ff00", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-gruvbox-dark-hard", .enabled = 0,
		.colorname = {
			"#1d2021", /* base00 */
			"#fb4934", /* base08 */
			"#b8bb26", /* base0B */
			"#fabd2f", /* base0A */
			"#83a598", /* base0D */
			"#d3869b", /* base0E */
			"#8ec07c", /* base0C */
			"#d5c4a1", /* base05 */
			"#665c54", /* base03 */
			"#fe8019", /* base09 */
			"#3c3836", /* base01 */
			"#504945", /* base02 */
			"#bdae93", /* base04 */
			"#ebdbb2", /* base06 */
			"#d65d0e", /* base0F */
			"#fbf1c7", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-gruvbox-dark-medium", .enabled = 0,
		.colorname = {
			"#282828", /* base00 */
			"#fb4934", /* base08 */
			"#b8bb26", /* base0B */
			"#fabd2f", /* base0A */
			"#83a598", /* base0D */
			"#d3869b", /* base0E */
			"#8ec07c", /* base0C */
			"#d5c4a1", /* base05 */
			"#665c54", /* base03 */
			"#fe8019", /* base09 */
			"#3c3836", /* base01 */
			"#504945", /* base02 */
			"#bdae93", /* base04 */
			"#ebdbb2", /* base06 */
			"#d65d0e", /* base0F */
			"#fbf1c7", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-gruvbox-dark-pale", .enabled = 0,
		.colorname = {
			"#262626", /* base00 */
			"#d75f5f", /* base08 */
			"#afaf00", /* base0B */
			"#ffaf00", /* base0A */
			"#83adad", /* base0D */
			"#d485ad", /* base0E */
			"#85ad85", /* base0C */
			"#dab997", /* base05 */
			"#8a8a8a", /* base03 */
			"#ff8700", /* base09 */
			"#3a3a3a", /* base01 */
			"#4e4e4e", /* base02 */
			"#949494", /* base04 */
			"#d5c4a1", /* base06 */
			"#d65d0e", /* base0F */
			"#ebdbb2", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-gruvbox-dark-soft", .enabled = 0,
		.colorname = {
			"#32302f", /* base00 */
			"#fb4934", /* base08 */
			"#b8bb26", /* base0B */
			"#fabd2f", /* base0A */
			"#83a598", /* base0D */
			"#d3869b", /* base0E */
			"#8ec07c", /* base0C */
			"#d5c4a1", /* base05 */
			"#665c54", /* base03 */
			"#fe8019", /* base09 */
			"#3c3836", /* base01 */
			"#504945", /* base02 */
			"#bdae93", /* base04 */
			"#ebdbb2", /* base06 */
			"#d65d0e", /* base0F */
			"#fbf1c7", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-gruvbox-light-hard", .enabled = 0,
		.colorname = {
			"#f9f5d7", /* base00 */
			"#9d0006", /* base08 */
			"#79740e", /* base0B */
			"#b57614", /* base0A */
			"#076678", /* base0D */
			"#8f3f71", /* base0E */
			"#427b58", /* base0C */
			"#504945", /* base05 */
			"#bdae93", /* base03 */
			"#af3a03", /* base09 */
			"#ebdbb2", /* base01 */
			"#d5c4a1", /* base02 */
			"#665c54", /* base04 */
			"#3c3836", /* base06 */
			"#d65d0e", /* base0F */
			"#282828", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-gruvbox-light-medium", .enabled = 0,
		.colorname = {
			"#fbf1c7", /* base00 */
			"#9d0006", /* base08 */
			"#79740e", /* base0B */
			"#b57614", /* base0A */
			"#076678", /* base0D */
			"#8f3f71", /* base0E */
			"#427b58", /* base0C */
			"#504945", /* base05 */
			"#bdae93", /* base03 */
			"#af3a03", /* base09 */
			"#ebdbb2", /* base01 */
			"#d5c4a1", /* base02 */
			"#665c54", /* base04 */
			"#3c3836", /* base06 */
			"#d65d0e", /* base0F */
			"#282828", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-gruvbox-light-soft", .enabled = 0,
		.colorname = {
			"#f2e5bc", /* base00 */
			"#9d0006", /* base08 */
			"#79740e", /* base0B */
			"#b57614", /* base0A */
			"#076678", /* base0D */
			"#8f3f71", /* base0E */
			"#427b58", /* base0C */
			"#504945", /* base05 */
			"#bdae93", /* base03 */
			"#af3a03", /* base09 */
			"#ebdbb2", /* base01 */
			"#d5c4a1", /* base02 */
			"#665c54", /* base04 */
			"#3c3836", /* base06 */
			"#d65d0e", /* base0F */
			"#282828", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-hardcore", .enabled = 1,
		.colorname = {
			"#212121", /* base00 */
			"#f92672", /* base08 */
			"#a6e22e", /* base0B */
			"#e6db74", /* base0A */
			"#66d9ef", /* base0D */
			"#9e6ffe", /* base0E */
			"#708387", /* base0C */
			"#cdcdcd", /* base05 */
			"#4A4A4A", /* base03 */
			"#fd971f", /* base09 */
			"#303030", /* base01 */
			"#353535", /* base02 */
			"#707070", /* base04 */
			"#e5e5e5", /* base06 */
			"#e8b882", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-harmonic-dark", .enabled = 1,
		.colorname = {
			"#0b1c2c", /* base00 */
			"#bf8b56", /* base08 */
			"#56bf8b", /* base0B */
			"#8bbf56", /* base0A */
			"#8b56bf", /* base0D */
			"#bf568b", /* base0E */
			"#568bbf", /* base0C */
			"#cbd6e2", /* base05 */
			"#627e99", /* base03 */
			"#bfbf56", /* base09 */
			"#223b54", /* base01 */
			"#405c79", /* base02 */
			"#aabcce", /* base04 */
			"#e5ebf1", /* base06 */
			"#bf5656", /* base0F */
			"#f7f9fb", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-harmonic-light", .enabled = 0,
		.colorname = {
			"#f7f9fb", /* base00 */
			"#bf8b56", /* base08 */
			"#56bf8b", /* base0B */
			"#8bbf56", /* base0A */
			"#8b56bf", /* base0D */
			"#bf568b", /* base0E */
			"#568bbf", /* base0C */
			"#405c79", /* base05 */
			"#aabcce", /* base03 */
			"#bfbf56", /* base09 */
			"#e5ebf1", /* base01 */
			"#cbd6e2", /* base02 */
			"#627e99", /* base04 */
			"#223b54", /* base06 */
			"#bf5656", /* base0F */
			"#0b1c2c", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-heetch", .enabled = 0,
		.colorname = {
			"#190134", /* base00 */
			"#27D9D5", /* base08 */
			"#C33678", /* base0B */
			"#8F6C97", /* base0A */
			"#BD0152", /* base0D */
			"#82034C", /* base0E */
			"#F80059", /* base0C */
			"#BDB6C5", /* base05 */
			"#7B6D8B", /* base03 */
			"#5BA2B6", /* base09 */
			"#392551", /* base01 */
			"#5A496E", /* base02 */
			"#9C92A8", /* base04 */
			"#DEDAE2", /* base06 */
			"#470546", /* base0F */
			"#FEFFFF", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-heetch-light", .enabled = 0,
		.colorname = {
			"#feffff", /* base00 */
			"#27d9d5", /* base08 */
			"#f80059", /* base0B */
			"#5ba2b6", /* base0A */
			"#47f9f5", /* base0D */
			"#bd0152", /* base0E */
			"#c33678", /* base0C */
			"#5a496e", /* base05 */
			"#9c92a8", /* base03 */
			"#bdb6c5", /* base09 */
			"#392551", /* base01 */
			"#7b6d8b", /* base02 */
			"#ddd6e5", /* base04 */
			"#470546", /* base06 */
			"#dedae2", /* base0F */
			"#190134", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-helios", .enabled = 0,
		.colorname = {
			"#1d2021", /* base00 */
			"#d72638", /* base08 */
			"#88b92d", /* base0B */
			"#f19d1a", /* base0A */
			"#1e8bac", /* base0D */
			"#be4264", /* base0E */
			"#1ba595", /* base0C */
			"#d5d5d5", /* base05 */
			"#6f7579", /* base03 */
			"#eb8413", /* base09 */
			"#383c3e", /* base01 */
			"#53585b", /* base02 */
			"#cdcdcd", /* base04 */
			"#dddddd", /* base06 */
			"#c85e0d", /* base0F */
			"#e5e5e5", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-hopscotch", .enabled = 0,
		.colorname = {
			"#322931", /* base00 */
			"#dd464c", /* base08 */
			"#8fc13e", /* base0B */
			"#fdcc59", /* base0A */
			"#1290bf", /* base0D */
			"#c85e7c", /* base0E */
			"#149b93", /* base0C */
			"#b9b5b8", /* base05 */
			"#797379", /* base03 */
			"#fd8b19", /* base09 */
			"#433b42", /* base01 */
			"#5c545b", /* base02 */
			"#989498", /* base04 */
			"#d5d3d5", /* base06 */
			"#b33508", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-horizon-dark", .enabled = 0,
		.colorname = {
			"#1C1E26", /* base00 */
			"#E93C58", /* base08 */
			"#EFAF8E", /* base0B */
			"#EFB993", /* base0A */
			"#DF5273", /* base0D */
			"#B072D1", /* base0E */
			"#24A8B4", /* base0C */
			"#CBCED0", /* base05 */
			"#6F6F70", /* base03 */
			"#E58D7D", /* base09 */
			"#232530", /* base01 */
			"#2E303E", /* base02 */
			"#9DA0A2", /* base04 */
			"#DCDFE4", /* base06 */
			"#E4A382", /* base0F */
			"#E3E6EE", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-horizon-light", .enabled = 0,
		.colorname = {
			"#FDF0ED", /* base00 */
			"#F7939B", /* base08 */
			"#94E1B0", /* base0B */
			"#FBE0D9", /* base0A */
			"#DA103F", /* base0D */
			"#1D8991", /* base0E */
			"#DC3318", /* base0C */
			"#403C3D", /* base05 */
			"#BDB3B1", /* base03 */
			"#F6661E", /* base09 */
			"#FADAD1", /* base01 */
			"#F9CBBE", /* base02 */
			"#948C8A", /* base04 */
			"#302C2D", /* base06 */
			"#E58C92", /* base0F */
			"#201C1D", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-horizon-terminal-dark", .enabled = 0,
		.colorname = {
			"#1C1E26", /* base00 */
			"#E95678", /* base08 */
			"#29D398", /* base0B */
			"#FAC29A", /* base0A */
			"#26BBD9", /* base0D */
			"#EE64AC", /* base0E */
			"#59E1E3", /* base0C */
			"#CBCED0", /* base05 */
			"#6F6F70", /* base03 */
			"#FAB795", /* base09 */
			"#232530", /* base01 */
			"#2E303E", /* base02 */
			"#9DA0A2", /* base04 */
			"#DCDFE4", /* base06 */
			"#F09383", /* base0F */
			"#E3E6EE", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-horizon-terminal-light", .enabled = 0,
		.colorname = {
			"#FDF0ED", /* base00 */
			"#E95678", /* base08 */
			"#29D398", /* base0B */
			"#FADAD1", /* base0A */
			"#26BBD9", /* base0D */
			"#EE64AC", /* base0E */
			"#59E1E3", /* base0C */
			"#403C3D", /* base05 */
			"#BDB3B1", /* base03 */
			"#F9CEC3", /* base09 */
			"#FADAD1", /* base01 */
			"#F9CBBE", /* base02 */
			"#948C8A", /* base04 */
			"#302C2D", /* base06 */
			"#F9CBBE", /* base0F */
			"#201C1D", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-humanoid-dark", .enabled = 0,
		.colorname = {
			"#232629", /* base00 */
			"#f11235", /* base08 */
			"#02d849", /* base0B */
			"#ffb627", /* base0A */
			"#00a6fb", /* base0D */
			"#f15ee3", /* base0E */
			"#0dd9d6", /* base0C */
			"#f8f8f2", /* base05 */
			"#60615d", /* base03 */
			"#ff9505", /* base09 */
			"#333b3d", /* base01 */
			"#484e54", /* base02 */
			"#c0c0bd", /* base04 */
			"#fcfcf6", /* base06 */
			"#b27701", /* base0F */
			"#fcfcfc", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-humanoid-light", .enabled = 0,
		.colorname = {
			"#f8f8f2", /* base00 */
			"#b0151a", /* base08 */
			"#388e3c", /* base0B */
			"#ffb627", /* base0A */
			"#0082c9", /* base0D */
			"#700f98", /* base0E */
			"#008e8e", /* base0C */
			"#232629", /* base05 */
			"#c0c0bd", /* base03 */
			"#ff3d00", /* base09 */
			"#efefe9", /* base01 */
			"#deded8", /* base02 */
			"#60615d", /* base04 */
			"#2f3337", /* base06 */
			"#b27701", /* base0F */
			"#070708", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-ia-dark", .enabled = 0,
		.colorname = {
			"#1a1a1a", /* base00 */
			"#d88568", /* base08 */
			"#83a471", /* base0B */
			"#b99353", /* base0A */
			"#8eccdd", /* base0D */
			"#b98eb2", /* base0E */
			"#7c9cae", /* base0C */
			"#cccccc", /* base05 */
			"#767676", /* base03 */
			"#d86868", /* base09 */
			"#222222", /* base01 */
			"#1d414d", /* base02 */
			"#b8b8b8", /* base04 */
			"#e8e8e8", /* base06 */
			"#8b6c37", /* base0F */
			"#f8f8f8", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-ia-light", .enabled = 0,
		.colorname = {
			"#f6f6f6", /* base00 */
			"#9c5a02", /* base08 */
			"#38781c", /* base0B */
			"#c48218", /* base0A */
			"#48bac2", /* base0D */
			"#a94598", /* base0E */
			"#2d6bb1", /* base0C */
			"#181818", /* base05 */
			"#898989", /* base03 */
			"#c43e18", /* base09 */
			"#dedede", /* base01 */
			"#bde5f2", /* base02 */
			"#767676", /* base04 */
			"#e8e8e8", /* base06 */
			"#8b6c37", /* base0F */
			"#f8f8f8", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-icy", .enabled = 0,
		.colorname = {
			"#021012", /* base00 */
			"#16c1d9", /* base08 */
			"#4dd0e1", /* base0B */
			"#80deea", /* base0A */
			"#00bcd4", /* base0D */
			"#00acc1", /* base0E */
			"#26c6da", /* base0C */
			"#095b67", /* base05 */
			"#052e34", /* base03 */
			"#b3ebf2", /* base09 */
			"#031619", /* base01 */
			"#041f23", /* base02 */
			"#064048", /* base04 */
			"#0c7c8c", /* base06 */
			"#0097a7", /* base0F */
			"#109cb0", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-irblack", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#ff6c60", /* base08 */
			"#a8ff60", /* base0B */
			"#ffffb6", /* base0A */
			"#96cbfe", /* base0D */
			"#ff73fd", /* base0E */
			"#c6c5fe", /* base0C */
			"#b5b3aa", /* base05 */
			"#6c6c66", /* base03 */
			"#e9c062", /* base09 */
			"#242422", /* base01 */
			"#484844", /* base02 */
			"#918f88", /* base04 */
			"#d9d7cc", /* base06 */
			"#b18a3d", /* base0F */
			"#fdfbee", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-isotope", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#ff0000", /* base08 */
			"#33ff00", /* base0B */
			"#ff0099", /* base0A */
			"#0066ff", /* base0D */
			"#cc00ff", /* base0E */
			"#00ffff", /* base0C */
			"#d0d0d0", /* base05 */
			"#808080", /* base03 */
			"#ff9900", /* base09 */
			"#404040", /* base01 */
			"#606060", /* base02 */
			"#c0c0c0", /* base04 */
			"#e0e0e0", /* base06 */
			"#3300ff", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-macintosh", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#dd0907", /* base08 */
			"#1fb714", /* base0B */
			"#fbf305", /* base0A */
			"#0000d3", /* base0D */
			"#4700a5", /* base0E */
			"#02abea", /* base0C */
			"#c0c0c0", /* base05 */
			"#808080", /* base03 */
			"#ff6403", /* base09 */
			"#404040", /* base01 */
			"#404040", /* base02 */
			"#808080", /* base04 */
			"#c0c0c0", /* base06 */
			"#90713a", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-marrakesh", .enabled = 0,
		.colorname = {
			"#201602", /* base00 */
			"#c35359", /* base08 */
			"#18974e", /* base0B */
			"#a88339", /* base0A */
			"#477ca1", /* base0D */
			"#8868b3", /* base0E */
			"#75a738", /* base0C */
			"#948e48", /* base05 */
			"#6c6823", /* base03 */
			"#b36144", /* base09 */
			"#302e00", /* base01 */
			"#5f5b17", /* base02 */
			"#86813b", /* base04 */
			"#ccc37a", /* base06 */
			"#b3588e", /* base0F */
			"#faf0a5", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-materia", .enabled = 0,
		.colorname = {
			"#263238", /* base00 */
			"#EC5F67", /* base08 */
			"#8BD649", /* base0B */
			"#FFCC00", /* base0A */
			"#89DDFF", /* base0D */
			"#82AAFF", /* base0E */
			"#80CBC4", /* base0C */
			"#CDD3DE", /* base05 */
			"#707880", /* base03 */
			"#EA9560", /* base09 */
			"#2C393F", /* base01 */
			"#37474F", /* base02 */
			"#C9CCD3", /* base04 */
			"#D5DBE5", /* base06 */
			"#EC5F67", /* base0F */
			"#FFFFFF", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-material-darker", .enabled = 0,
		.colorname = {
			"#212121", /* base00 */
			"#F07178", /* base08 */
			"#C3E88D", /* base0B */
			"#FFCB6B", /* base0A */
			"#82AAFF", /* base0D */
			"#C792EA", /* base0E */
			"#89DDFF", /* base0C */
			"#EEFFFF", /* base05 */
			"#4A4A4A", /* base03 */
			"#F78C6C", /* base09 */
			"#303030", /* base01 */
			"#353535", /* base02 */
			"#B2CCD6", /* base04 */
			"#EEFFFF", /* base06 */
			"#FF5370", /* base0F */
			"#FFFFFF", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-material", .enabled = 0,
		.colorname = {
			"#263238", /* base00 */
			"#F07178", /* base08 */
			"#C3E88D", /* base0B */
			"#FFCB6B", /* base0A */
			"#82AAFF", /* base0D */
			"#C792EA", /* base0E */
			"#89DDFF", /* base0C */
			"#EEFFFF", /* base05 */
			"#546E7A", /* base03 */
			"#F78C6C", /* base09 */
			"#2E3C43", /* base01 */
			"#314549", /* base02 */
			"#B2CCD6", /* base04 */
			"#EEFFFF", /* base06 */
			"#FF5370", /* base0F */
			"#FFFFFF", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-material-lighter", .enabled = 0,
		.colorname = {
			"#FAFAFA", /* base00 */
			"#FF5370", /* base08 */
			"#91B859", /* base0B */
			"#FFB62C", /* base0A */
			"#6182B8", /* base0D */
			"#7C4DFF", /* base0E */
			"#39ADB5", /* base0C */
			"#80CBC4", /* base05 */
			"#CCD7DA", /* base03 */
			"#F76D47", /* base09 */
			"#E7EAEC", /* base01 */
			"#CCEAE7", /* base02 */
			"#8796B0", /* base04 */
			"#80CBC4", /* base06 */
			"#E53935", /* base0F */
			"#FFFFFF", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-material-palenight", .enabled = 0,
		.colorname = {
			"#292D3E", /* base00 */
			"#F07178", /* base08 */
			"#C3E88D", /* base0B */
			"#FFCB6B", /* base0A */
			"#82AAFF", /* base0D */
			"#C792EA", /* base0E */
			"#89DDFF", /* base0C */
			"#959DCB", /* base05 */
			"#676E95", /* base03 */
			"#F78C6C", /* base09 */
			"#444267", /* base01 */
			"#32374D", /* base02 */
			"#8796B0", /* base04 */
			"#959DCB", /* base06 */
			"#FF5370", /* base0F */
			"#FFFFFF", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-material-vivid", .enabled = 0,
		.colorname = {
			"#202124", /* base00 */
			"#f44336", /* base08 */
			"#00e676", /* base0B */
			"#ffeb3b", /* base0A */
			"#2196f3", /* base0D */
			"#673ab7", /* base0E */
			"#00bcd4", /* base0C */
			"#80868b", /* base05 */
			"#44464d", /* base03 */
			"#ff9800", /* base09 */
			"#27292c", /* base01 */
			"#323639", /* base02 */
			"#676c71", /* base04 */
			"#9e9e9e", /* base06 */
			"#8d6e63", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-mellow-purple", .enabled = 0,
		.colorname = {
			"#1e0528", /* base00 */
			"#00d9e9", /* base08 */
			"#05cb0d", /* base0B */
			"#955ae7", /* base0A */
			"#550068", /* base0D */
			"#8991bb", /* base0E */
			"#b900b1", /* base0C */
			"#ffeeff", /* base05 */
			"#320f55", /* base03 */
			"#aa00a3", /* base09 */
			"#1A092D", /* base01 */
			"#331354", /* base02 */
			"#873582", /* base04 */
			"#ffeeff", /* base06 */
			"#4d6fff", /* base0F */
			"#f8c0ff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-mexico-light", .enabled = 0,
		.colorname = {
			"#f8f8f8", /* base00 */
			"#ab4642", /* base08 */
			"#538947", /* base0B */
			"#f79a0e", /* base0A */
			"#7cafc2", /* base0D */
			"#96609e", /* base0E */
			"#4b8093", /* base0C */
			"#383838", /* base05 */
			"#b8b8b8", /* base03 */
			"#dc9656", /* base09 */
			"#e8e8e8", /* base01 */
			"#d8d8d8", /* base02 */
			"#585858", /* base04 */
			"#282828", /* base06 */
			"#a16946", /* base0F */
			"#181818", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-mocha", .enabled = 0,
		.colorname = {
			"#3B3228", /* base00 */
			"#cb6077", /* base08 */
			"#beb55b", /* base0B */
			"#f4bc87", /* base0A */
			"#8ab3b5", /* base0D */
			"#a89bb9", /* base0E */
			"#7bbda4", /* base0C */
			"#d0c8c6", /* base05 */
			"#7e705a", /* base03 */
			"#d28b71", /* base09 */
			"#534636", /* base01 */
			"#645240", /* base02 */
			"#b8afad", /* base04 */
			"#e9e1dd", /* base06 */
			"#bb9584", /* base0F */
			"#f5eeeb", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-monokai", .enabled = 0,
		.colorname = {
			"#272822", /* base00 */
			"#f92672", /* base08 */
			"#a6e22e", /* base0B */
			"#f4bf75", /* base0A */
			"#66d9ef", /* base0D */
			"#ae81ff", /* base0E */
			"#a1efe4", /* base0C */
			"#f8f8f2", /* base05 */
			"#75715e", /* base03 */
			"#fd971f", /* base09 */
			"#383830", /* base01 */
			"#49483e", /* base02 */
			"#a59f85", /* base04 */
			"#f5f4f1", /* base06 */
			"#cc6633", /* base0F */
			"#f9f8f5", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-nebula", .enabled = 0,
		.colorname = {
			"#22273b", /* base00 */
			"#777abc", /* base08 */
			"#6562a8", /* base0B */
			"#4f9062", /* base0A */
			"#4d6bb6", /* base0D */
			"#716cae", /* base0E */
			"#226f68", /* base0C */
			"#a4a6a9", /* base05 */
			"#6e6f72", /* base03 */
			"#94929e", /* base09 */
			"#414f60", /* base01 */
			"#5a8380", /* base02 */
			"#87888b", /* base04 */
			"#c7c9cd", /* base06 */
			"#8c70a7", /* base0F */
			"#8dbdaa", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-nord", .enabled = 0,
		.colorname = {
			"#2E3440", /* base00 */
			"#BF616A", /* base08 */
			"#A3BE8C", /* base0B */
			"#EBCB8B", /* base0A */
			"#81A1C1", /* base0D */
			"#B48EAD", /* base0E */
			"#88C0D0", /* base0C */
			"#E5E9F0", /* base05 */
			"#4C566A", /* base03 */
			"#D08770", /* base09 */
			"#3B4252", /* base01 */
			"#434C5E", /* base02 */
			"#D8DEE9", /* base04 */
			"#ECEFF4", /* base06 */
			"#5E81AC", /* base0F */
			"#8FBCBB", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-nova", .enabled = 0,
		.colorname = {
			"#3C4C55", /* base00 */
			"#83AFE5", /* base08 */
			"#7FC1CA", /* base0B */
			"#A8CE93", /* base0A */
			"#83AFE5", /* base0D */
			"#9A93E1", /* base0E */
			"#F2C38F", /* base0C */
			"#C5D4DD", /* base05 */
			"#899BA6", /* base03 */
			"#7FC1CA", /* base09 */
			"#556873", /* base01 */
			"#6A7D89", /* base02 */
			"#899BA6", /* base04 */
			"#899BA6", /* base06 */
			"#F2C38F", /* base0F */
			"#556873", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-ocean", .enabled = 0,
		.colorname = {
			"#2b303b", /* base00 */
			"#bf616a", /* base08 */
			"#a3be8c", /* base0B */
			"#ebcb8b", /* base0A */
			"#8fa1b3", /* base0D */
			"#b48ead", /* base0E */
			"#96b5b4", /* base0C */
			"#c0c5ce", /* base05 */
			"#65737e", /* base03 */
			"#d08770", /* base09 */
			"#343d46", /* base01 */
			"#4f5b66", /* base02 */
			"#a7adba", /* base04 */
			"#dfe1e8", /* base06 */
			"#ab7967", /* base0F */
			"#eff1f5", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-oceanicnext", .enabled = 0,
		.colorname = {
			"#1B2B34", /* base00 */
			"#EC5f67", /* base08 */
			"#99C794", /* base0B */
			"#FAC863", /* base0A */
			"#6699CC", /* base0D */
			"#C594C5", /* base0E */
			"#5FB3B3", /* base0C */
			"#C0C5CE", /* base05 */
			"#65737E", /* base03 */
			"#F99157", /* base09 */
			"#343D46", /* base01 */
			"#4F5B66", /* base02 */
			"#A7ADBA", /* base04 */
			"#CDD3DE", /* base06 */
			"#AB7967", /* base0F */
			"#D8DEE9", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-onedark", .enabled = 0,
		.colorname = {
			"#282c34", /* base00 */
			"#e06c75", /* base08 */
			"#98c379", /* base0B */
			"#e5c07b", /* base0A */
			"#61afef", /* base0D */
			"#c678dd", /* base0E */
			"#56b6c2", /* base0C */
			"#abb2bf", /* base05 */
			"#545862", /* base03 */
			"#d19a66", /* base09 */
			"#353b45", /* base01 */
			"#3e4451", /* base02 */
			"#565c64", /* base04 */
			"#b6bdca", /* base06 */
			"#be5046", /* base0F */
			"#c8ccd4", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-one-light", .enabled = 0,
		.colorname = {
			"#fafafa", /* base00 */
			"#ca1243", /* base08 */
			"#50a14f", /* base0B */
			"#c18401", /* base0A */
			"#4078f2", /* base0D */
			"#a626a4", /* base0E */
			"#0184bc", /* base0C */
			"#383a42", /* base05 */
			"#a0a1a7", /* base03 */
			"#d75f00", /* base09 */
			"#f0f0f1", /* base01 */
			"#e5e5e6", /* base02 */
			"#696c77", /* base04 */
			"#202227", /* base06 */
			"#986801", /* base0F */
			"#090a0b", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-outrun-dark", .enabled = 0,
		.colorname = {
			"#00002A", /* base00 */
			"#FF4242", /* base08 */
			"#59F176", /* base0B */
			"#F3E877", /* base0A */
			"#66B0FF", /* base0D */
			"#F10596", /* base0E */
			"#0EF0F0", /* base0C */
			"#D0D0FA", /* base05 */
			"#50507A", /* base03 */
			"#FC8D28", /* base09 */
			"#20204A", /* base01 */
			"#30305A", /* base02 */
			"#B0B0DA", /* base04 */
			"#E0E0FF", /* base06 */
			"#F003EF", /* base0F */
			"#F5F5FF", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-papercolor-dark", .enabled = 0,
		.colorname = {
			"#1c1c1c", /* base00 */
			"#585858", /* base08 */
			"#af87d7", /* base0B */
			"#afd700", /* base0A */
			"#ff5faf", /* base0D */
			"#00afaf", /* base0E */
			"#ffaf00", /* base0C */
			"#808080", /* base05 */
			"#d7af5f", /* base03 */
			"#5faf5f", /* base09 */
			"#af005f", /* base01 */
			"#5faf00", /* base02 */
			"#5fafd7", /* base04 */
			"#d7875f", /* base06 */
			"#5f8787", /* base0F */
			"#d0d0d0", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-papercolor-light", .enabled = 0,
		.colorname = {
			"#eeeeee", /* base00 */
			"#bcbcbc", /* base08 */
			"#8700af", /* base0B */
			"#d70087", /* base0A */
			"#d75f00", /* base0D */
			"#005faf", /* base0E */
			"#d75f00", /* base0C */
			"#444444", /* base05 */
			"#5f8700", /* base03 */
			"#d70000", /* base09 */
			"#af0000", /* base01 */
			"#008700", /* base02 */
			"#0087af", /* base04 */
			"#005f87", /* base06 */
			"#005f87", /* base0F */
			"#878787", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-paraiso", .enabled = 0,
		.colorname = {
			"#2f1e2e", /* base00 */
			"#ef6155", /* base08 */
			"#48b685", /* base0B */
			"#fec418", /* base0A */
			"#06b6ef", /* base0D */
			"#815ba4", /* base0E */
			"#5bc4bf", /* base0C */
			"#a39e9b", /* base05 */
			"#776e71", /* base03 */
			"#f99b15", /* base09 */
			"#41323f", /* base01 */
			"#4f424c", /* base02 */
			"#8d8687", /* base04 */
			"#b9b6b0", /* base06 */
			"#e96ba8", /* base0F */
			"#e7e9db", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-pasque", .enabled = 0,
		.colorname = {
			"#271C3A", /* base00 */
			"#A92258", /* base08 */
			"#C6914B", /* base0B */
			"#804ead", /* base0A */
			"#8E7DC6", /* base0D */
			"#953B9D", /* base0E */
			"#7263AA", /* base0C */
			"#DEDCDF", /* base05 */
			"#5D5766", /* base03 */
			"#918889", /* base09 */
			"#100323", /* base01 */
			"#3E2D5C", /* base02 */
			"#BEBCBF", /* base04 */
			"#EDEAEF", /* base06 */
			"#59325C", /* base0F */
			"#BBAADD", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-phd", .enabled = 1,
		.colorname = {
			"#061229", /* base00 */
			"#d07346", /* base08 */
			"#99bf52", /* base0B */
			"#fbd461", /* base0A */
			"#5299bf", /* base0D */
			"#9989cc", /* base0E */
			"#72b9bf", /* base0C */
			"#b8bbc2", /* base05 */
			"#717885", /* base03 */
			"#f0a000", /* base09 */
			"#2a3448", /* base01 */
			"#4d5666", /* base02 */
			"#9a99a3", /* base04 */
			"#dbdde0", /* base06 */
			"#b08060", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-pico", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#ff004d", /* base08 */
			"#00e756", /* base0B */
			"#fff024", /* base0A */
			"#83769c", /* base0D */
			"#ff77a8", /* base0E */
			"#29adff", /* base0C */
			"#5f574f", /* base05 */
			"#008751", /* base03 */
			"#ffa300", /* base09 */
			"#1d2b53", /* base01 */
			"#7e2553", /* base02 */
			"#ab5236", /* base04 */
			"#c2c3c7", /* base06 */
			"#ffccaa", /* base0F */
			"#fff1e8", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-pop", .enabled = 0,
		.colorname = {
			"#000000", /* base00 */
			"#eb008a", /* base08 */
			"#37b349", /* base0B */
			"#f8ca12", /* base0A */
			"#0e5a94", /* base0D */
			"#b31e8d", /* base0E */
			"#00aabb", /* base0C */
			"#d0d0d0", /* base05 */
			"#505050", /* base03 */
			"#f29333", /* base09 */
			"#202020", /* base01 */
			"#303030", /* base02 */
			"#b0b0b0", /* base04 */
			"#e0e0e0", /* base06 */
			"#7a2d00", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-porple", .enabled = 0,
		.colorname = {
			"#292c36", /* base00 */
			"#f84547", /* base08 */
			"#95c76f", /* base0B */
			"#efa16b", /* base0A */
			"#8485ce", /* base0D */
			"#b74989", /* base0E */
			"#64878f", /* base0C */
			"#d8d8d8", /* base05 */
			"#65568a", /* base03 */
			"#d28e5d", /* base09 */
			"#333344", /* base01 */
			"#474160", /* base02 */
			"#b8b8b8", /* base04 */
			"#e8e8e8", /* base06 */
			"#986841", /* base0F */
			"#f8f8f8", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-railscasts", .enabled = 0,
		.colorname = {
			"#2b2b2b", /* base00 */
			"#da4939", /* base08 */
			"#a5c261", /* base0B */
			"#ffc66d", /* base0A */
			"#6d9cbe", /* base0D */
			"#b6b3eb", /* base0E */
			"#519f50", /* base0C */
			"#e6e1dc", /* base05 */
			"#5a647e", /* base03 */
			"#cc7833", /* base09 */
			"#272935", /* base01 */
			"#3a4055", /* base02 */
			"#d4cfc9", /* base04 */
			"#f4f1ed", /* base06 */
			"#bc9458", /* base0F */
			"#f9f7f3", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-rebecca", .enabled = 0,
		.colorname = {
			"#292a44", /* base00 */
			"#a0a0c5", /* base08 */
			"#6dfedf", /* base0B */
			"#ae81ff", /* base0A */
			"#2de0a7", /* base0D */
			"#7aa5ff", /* base0E */
			"#8eaee0", /* base0C */
			"#f1eff8", /* base05 */
			"#666699", /* base03 */
			"#efe4a1", /* base09 */
			"#663399", /* base01 */
			"#383a62", /* base02 */
			"#a0a0c5", /* base04 */
			"#ccccff", /* base06 */
			"#ff79c6", /* base0F */
			"#53495d", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-sandcastle", .enabled = 0,
		.colorname = {
			"#282c34", /* base00 */
			"#83a598", /* base08 */
			"#528b8b", /* base0B */
			"#a07e3b", /* base0A */
			"#83a598", /* base0D */
			"#d75f5f", /* base0E */
			"#83a598", /* base0C */
			"#a89984", /* base05 */
			"#665c54", /* base03 */
			"#a07e3b", /* base09 */
			"#2c323b", /* base01 */
			"#3e4451", /* base02 */
			"#928374", /* base04 */
			"#d5c4a1", /* base06 */
			"#a87322", /* base0F */
			"#fdf4c1", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-seti", .enabled = 0,
		.colorname = {
			"#151718", /* base00 */
			"#Cd3f45", /* base08 */
			"#9fca56", /* base0B */
			"#e6cd69", /* base0A */
			"#55b5db", /* base0D */
			"#a074c4", /* base0E */
			"#55dbbe", /* base0C */
			"#d6d6d6", /* base05 */
			"#41535B", /* base03 */
			"#db7b55", /* base09 */
			"#282a2b", /* base01 */
			"#3B758C", /* base02 */
			"#43a5d5", /* base04 */
			"#eeeeee", /* base06 */
			"#8a553f", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-shapeshifter", .enabled = 0,
		.colorname = {
			"#f9f9f9", /* base00 */
			"#e92f2f", /* base08 */
			"#0ed839", /* base0B */
			"#dddd13", /* base0A */
			"#3b48e3", /* base0D */
			"#f996e2", /* base0E */
			"#23edda", /* base0C */
			"#102015", /* base05 */
			"#555555", /* base03 */
			"#e09448", /* base09 */
			"#e0e0e0", /* base01 */
			"#ababab", /* base02 */
			"#343434", /* base04 */
			"#040404", /* base06 */
			"#69542d", /* base0F */
			"#000000", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-snazzy", .enabled = 0,
		.colorname = {
			"#282a36", /* base00 */
			"#ff5c57", /* base08 */
			"#5af78e", /* base0B */
			"#f3f99d", /* base0A */
			"#57c7ff", /* base0D */
			"#ff6ac1", /* base0E */
			"#9aedfe", /* base0C */
			"#e2e4e5", /* base05 */
			"#78787e", /* base03 */
			"#ff9f43", /* base09 */
			"#34353e", /* base01 */
			"#43454f", /* base02 */
			"#a5a5a9", /* base04 */
			"#eff0eb", /* base06 */
			"#b2643c", /* base0F */
			"#f1f1f0", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-solarflare", .enabled = 0,
		.colorname = {
			"#18262F", /* base00 */
			"#EF5253", /* base08 */
			"#7CC844", /* base0B */
			"#E4B51C", /* base0A */
			"#33B5E1", /* base0D */
			"#A363D5", /* base0E */
			"#52CBB0", /* base0C */
			"#A6AFB8", /* base05 */
			"#667581", /* base03 */
			"#E66B2B", /* base09 */
			"#222E38", /* base01 */
			"#586875", /* base02 */
			"#85939E", /* base04 */
			"#E8E9ED", /* base06 */
			"#D73C9A", /* base0F */
			"#F5F7FA", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-solarized-dark", .enabled = 0,
		.colorname = {
			"#002b36", /* base00 */
			"#dc322f", /* base08 */
			"#859900", /* base0B */
			"#b58900", /* base0A */
			"#268bd2", /* base0D */
			"#6c71c4", /* base0E */
			"#2aa198", /* base0C */
			"#93a1a1", /* base05 */
			"#657b83", /* base03 */
			"#cb4b16", /* base09 */
			"#073642", /* base01 */
			"#586e75", /* base02 */
			"#839496", /* base04 */
			"#eee8d5", /* base06 */
			"#d33682", /* base0F */
			"#fdf6e3", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-solarized-light", .enabled = 0,
		.colorname = {
			"#fdf6e3", /* base00 */
			"#dc322f", /* base08 */
			"#859900", /* base0B */
			"#b58900", /* base0A */
			"#268bd2", /* base0D */
			"#6c71c4", /* base0E */
			"#2aa198", /* base0C */
			"#586e75", /* base05 */
			"#839496", /* base03 */
			"#cb4b16", /* base09 */
			"#eee8d5", /* base01 */
			"#93a1a1", /* base02 */
			"#657b83", /* base04 */
			"#073642", /* base06 */
			"#d33682", /* base0F */
			"#002b36", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-spacemacs", .enabled = 0,
		.colorname = {
			"#1f2022", /* base00 */
			"#f2241f", /* base08 */
			"#67b11d", /* base0B */
			"#b1951d", /* base0A */
			"#4f97d7", /* base0D */
			"#a31db1", /* base0E */
			"#2d9574", /* base0C */
			"#a3a3a3", /* base05 */
			"#585858", /* base03 */
			"#ffa500", /* base09 */
			"#282828", /* base01 */
			"#444155", /* base02 */
			"#b8b8b8", /* base04 */
			"#e8e8e8", /* base06 */
			"#b03060", /* base0F */
			"#f8f8f8", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-summercamp", .enabled = 0,
		.colorname = {
			"#1c1810", /* base00 */
			"#e35142", /* base08 */
			"#5ceb5a", /* base0B */
			"#f2ff27", /* base0A */
			"#489bf0", /* base0D */
			"#FF8080", /* base0E */
			"#5aebbc", /* base0C */
			"#736e55", /* base05 */
			"#504b38", /* base03 */
			"#fba11b", /* base09 */
			"#2a261c", /* base01 */
			"#3a3527", /* base02 */
			"#5f5b45", /* base04 */
			"#bab696", /* base06 */
			"#F69BE7", /* base0F */
			"#f8f5de", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-summerfruit-dark", .enabled = 0,
		.colorname = {
			"#151515", /* base00 */
			"#FF0086", /* base08 */
			"#00C918", /* base0B */
			"#ABA800", /* base0A */
			"#3777E6", /* base0D */
			"#AD00A1", /* base0E */
			"#1FAAAA", /* base0C */
			"#D0D0D0", /* base05 */
			"#505050", /* base03 */
			"#FD8900", /* base09 */
			"#202020", /* base01 */
			"#303030", /* base02 */
			"#B0B0B0", /* base04 */
			"#E0E0E0", /* base06 */
			"#CC6633", /* base0F */
			"#FFFFFF", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-summerfruit-light", .enabled = 0,
		.colorname = {
			"#FFFFFF", /* base00 */
			"#FF0086", /* base08 */
			"#00C918", /* base0B */
			"#ABA800", /* base0A */
			"#3777E6", /* base0D */
			"#AD00A1", /* base0E */
			"#1FAAAA", /* base0C */
			"#101010", /* base05 */
			"#B0B0B0", /* base03 */
			"#FD8900", /* base09 */
			"#E0E0E0", /* base01 */
			"#D0D0D0", /* base02 */
			"#000000", /* base04 */
			"#151515", /* base06 */
			"#CC6633", /* base0F */
			"#202020", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-synth-midnight-dark", .enabled = 1,
		.colorname = {
			"#050608", /* base00 */
			"#b53b50", /* base08 */
			"#06ea61", /* base0B */
			"#d7df27", /* base0A */
			"#03aeff", /* base0D */
			"#ea5ce2", /* base0E */
			"#42fff9", /* base0C */
			"#c1c3c4", /* base05 */
			"#474849", /* base03 */
			"#ea770d", /* base09 */
			"#1a1b1c", /* base01 */
			"#28292a", /* base02 */
			"#a3a5a6", /* base04 */
			"#cfd1d2", /* base06 */
			"#cd6320", /* base0F */
			"#dddfe0", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-tango", .enabled = 0,
		.colorname = {
			"#2e3436", /* base00 */
			"#cc0000", /* base08 */
			"#4e9a06", /* base0B */
			"#c4a000", /* base0A */
			"#3465a4", /* base0D */
			"#75507b", /* base0E */
			"#06989a", /* base0C */
			"#d3d7cf", /* base05 */
			"#555753", /* base03 */
			"#ef2929", /* base09 */
			"#8ae234", /* base01 */
			"#fce94f", /* base02 */
			"#729fcf", /* base04 */
			"#ad7fa8", /* base06 */
			"#34e2e2", /* base0F */
			"#eeeeec", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-tomorrow", .enabled = 0,
		.colorname = {
			"#ffffff", /* base00 */
			"#c82829", /* base08 */
			"#718c00", /* base0B */
			"#eab700", /* base0A */
			"#4271ae", /* base0D */
			"#8959a8", /* base0E */
			"#3e999f", /* base0C */
			"#4d4d4c", /* base05 */
			"#8e908c", /* base03 */
			"#f5871f", /* base09 */
			"#e0e0e0", /* base01 */
			"#d6d6d6", /* base02 */
			"#969896", /* base04 */
			"#282a2e", /* base06 */
			"#a3685a", /* base0F */
			"#1d1f21", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-tomorrow-night-eighties", .enabled = 0,
		.colorname = {
			"#2d2d2d", /* base00 */
			"#f2777a", /* base08 */
			"#99cc99", /* base0B */
			"#ffcc66", /* base0A */
			"#6699cc", /* base0D */
			"#cc99cc", /* base0E */
			"#66cccc", /* base0C */
			"#cccccc", /* base05 */
			"#999999", /* base03 */
			"#f99157", /* base09 */
			"#393939", /* base01 */
			"#515151", /* base02 */
			"#b4b7b4", /* base04 */
			"#e0e0e0", /* base06 */
			"#a3685a", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-tomorrow-night", .enabled = 0,
		.colorname = {
			"#1d1f21", /* base00 */
			"#cc6666", /* base08 */
			"#b5bd68", /* base0B */
			"#f0c674", /* base0A */
			"#81a2be", /* base0D */
			"#b294bb", /* base0E */
			"#8abeb7", /* base0C */
			"#c5c8c6", /* base05 */
			"#969896", /* base03 */
			"#de935f", /* base09 */
			"#282a2e", /* base01 */
			"#373b41", /* base02 */
			"#b4b7b4", /* base04 */
			"#e0e0e0", /* base06 */
			"#a3685a", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-tube", .enabled = 0,
		.colorname = {
			"#231f20", /* base00 */
			"#ee2e24", /* base08 */
			"#00853e", /* base0B */
			"#ffd204", /* base0A */
			"#009ddc", /* base0D */
			"#98005d", /* base0E */
			"#85cebc", /* base0C */
			"#d9d8d8", /* base05 */
			"#737171", /* base03 */
			"#f386a1", /* base09 */
			"#1c3f95", /* base01 */
			"#5a5758", /* base02 */
			"#959ca1", /* base04 */
			"#e7e7e8", /* base06 */
			"#b06110", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-twilight", .enabled = 0,
		.colorname = {
			"#1e1e1e", /* base00 */
			"#cf6a4c", /* base08 */
			"#8f9d6a", /* base0B */
			"#f9ee98", /* base0A */
			"#7587a6", /* base0D */
			"#9b859d", /* base0E */
			"#afc4db", /* base0C */
			"#a7a7a7", /* base05 */
			"#5f5a60", /* base03 */
			"#cda869", /* base09 */
			"#323537", /* base01 */
			"#464b50", /* base02 */
			"#838184", /* base04 */
			"#c3c3c3", /* base06 */
			"#9b703f", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-unikitty-dark", .enabled = 0,
		.colorname = {
			"#2e2a31", /* base00 */
			"#d8137f", /* base08 */
			"#17ad98", /* base0B */
			"#dc8a0e", /* base0A */
			"#796af5", /* base0D */
			"#bb60ea", /* base0E */
			"#149bda", /* base0C */
			"#bcbabe", /* base05 */
			"#838085", /* base03 */
			"#d65407", /* base09 */
			"#4a464d", /* base01 */
			"#666369", /* base02 */
			"#9f9da2", /* base04 */
			"#d8d7da", /* base06 */
			"#c720ca", /* base0F */
			"#f5f4f7", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-unikitty-light", .enabled = 0,
		.colorname = {
			"#ffffff", /* base00 */
			"#d8137f", /* base08 */
			"#17ad98", /* base0B */
			"#dc8a0e", /* base0A */
			"#775dff", /* base0D */
			"#aa17e6", /* base0E */
			"#149bda", /* base0C */
			"#6c696e", /* base05 */
			"#a7a5a8", /* base03 */
			"#d65407", /* base09 */
			"#e1e1e2", /* base01 */
			"#c4c3c5", /* base02 */
			"#89878b", /* base04 */
			"#4f4b51", /* base06 */
			"#e013d0", /* base0F */
			"#322d34", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-vulcan", .enabled = 0,
		.colorname = {
			"#041523", /* base00 */
			"#818591", /* base08 */
			"#977d7c", /* base0B */
			"#adb4b9", /* base0A */
			"#977d7c", /* base0D */
			"#9198a3", /* base0E */
			"#977d7c", /* base0C */
			"#5b778c", /* base05 */
			"#7a5759", /* base03 */
			"#9198a3", /* base09 */
			"#122339", /* base01 */
			"#003552", /* base02 */
			"#6b6977", /* base04 */
			"#333238", /* base06 */
			"#977d7c", /* base0F */
			"#214d68", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-woodland", .enabled = 0,
		.colorname = {
			"#231e18", /* base00 */
			"#d35c5c", /* base08 */
			"#b7ba53", /* base0B */
			"#e0ac16", /* base0A */
			"#88a4d3", /* base0D */
			"#bb90e2", /* base0E */
			"#6eb958", /* base0C */
			"#cabcb1", /* base05 */
			"#9d8b70", /* base03 */
			"#ca7f32", /* base09 */
			"#302b25", /* base01 */
			"#48413a", /* base02 */
			"#b4a490", /* base04 */
			"#d7c8bc", /* base06 */
			"#b49368", /* base0F */
			"#e4d4c8", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-xcode-dusk", .enabled = 0,
		.colorname = {
			"#282B35", /* base00 */
			"#B21889", /* base08 */
			"#DF0002", /* base0B */
			"#438288", /* base0A */
			"#790EAD", /* base0D */
			"#B21889", /* base0E */
			"#00A0BE", /* base0C */
			"#939599", /* base05 */
			"#686A71", /* base03 */
			"#786DC5", /* base09 */
			"#3D4048", /* base01 */
			"#53555D", /* base02 */
			"#7E8086", /* base04 */
			"#A9AAAE", /* base06 */
			"#C77C48", /* base0F */
			"#BEBFC2", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
	{
		.name = "base16-zenburn", .enabled = 0,
		.colorname = {
			"#383838", /* base00 */
			"#dca3a3", /* base08 */
			"#5f7f5f", /* base0B */
			"#e0cf9f", /* base0A */
			"#7cb8bb", /* base0D */
			"#dc8cc3", /* base0E */
			"#93e0e3", /* base0C */
			"#dcdccc", /* base05 */
			"#6f6f6f", /* base03 */
			"#dfaf8f", /* base09 */
			"#404040", /* base01 */
			"#606060", /* base02 */
			"#808080", /* base04 */
			"#c0c0c0", /* base06 */
			"#000000", /* base0F */
			"#ffffff", /* base07 */
		},
		.defaultfg = 7,
		.defaultbg = 0,
		.defaultcs = 13,
		.defaultrcs = 0,
	},
};
