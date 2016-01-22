#ifndef WEBIF_PAGES_H_
#define WEBIF_PAGES_H_

enum template_types {
	TEMPLATE_TYPE_TEXT = 0,
	TEMPLATE_TYPE_PNG  = 1,
	TEMPLATE_TYPE_GIF  = 2,
	TEMPLATE_TYPE_ICO  = 3,
	TEMPLATE_TYPE_JPG  = 4,
};

#define COMPRESSED_TEMPLATES 1

struct template {
	uint32_t tpl_name_ofs;
	uint32_t tpl_data_ofs;
	uint32_t tpl_deps_ofs;
	uint32_t tpl_data_len;
	uint8_t tpl_type;
};

int32_t templates_count(void);
bool template_is_image(enum template_types tpl_type);
const char *template_get_mimetype(enum template_types tpl_type);
const struct template *templates_get(void);
void templates_get_data(const char **data, size_t *data_len, size_t *odata_len);

#endif
