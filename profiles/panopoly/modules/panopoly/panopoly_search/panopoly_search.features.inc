<?php
/**
 * @file
 * panopoly_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function panopoly_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function panopoly_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function panopoly_search_default_search_api_index() {
  $items = array();
  $items['database_node_index'] = entity_import('search_api_index', '{
    "name" : "Database Node Index",
    "machine_name" : "database_node_index",
    "description" : null,
    "server" : "database_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [] },
      "index_directly" : 1,
      "cron_limit" : "60",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "created" : { "type" : "date" },
        "domain_domain_id" : { "type" : "list\\u003Cinteger\\u003E" },
        "domain_sitename" : { "type" : "list\\u003Cstring\\u003E" },
        "domain_subdomain" : { "type" : "list\\u003Cstring\\u003E" },
        "field_article_top_text_black" : { "type" : "text" },
        "field_article_top_text_white" : { "type" : "text" },
        "field_cm_article_subtitle" : { "type" : "text", "boost" : "2.0" },
        "field_cm_article_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_cm_article_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_cm_event_comment" : { "type" : "text" },
        "field_cm_event_hall" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_cm_event_hall:name" : { "type" : "text" },
        "field_cm_event_short_title" : { "type" : "text", "boost" : "5.0" },
        "field_cm_event_subtitle" : { "type" : "text", "boost" : "2.0" },
        "field_cm_movie_alt_title" : { "type" : "text" },
        "field_cm_movie_country" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_cm_movie_credits" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_cm_movie_genre" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_cm_movie_internal_id" : { "type" : "string" },
        "field_cm_movie_language" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_cm_movie_meta_credit" : { "type" : "text", "boost" : "2.0" },
        "field_cm_movie_subtitle" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_cm_movie_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_cm_movie_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_cm_movie_year" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_cm_moviegroup_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_cm_moviegroup_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_cm_person_first_name" : { "type" : "text" },
        "field_cm_person_job_title" : { "type" : "text" },
        "field_cm_person_last_name" : { "type" : "text" },
        "field_cm_person_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_cm_person_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_cm_person_type:name" : { "type" : "text" },
        "field_lobby" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_lobby:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_main_event_credit" : { "type" : "text" },
        "field_mc_teaser_toptxt_blk" : { "type" : "text", "boost" : "0.8" },
        "field_mc_teaser_toptxt_white" : { "type" : "text", "boost" : "0.8" },
        "field_movie_group_top_text_black" : { "type" : "text" },
        "field_movie_group_top_text_white" : { "type" : "text" },
        "field_search_additions" : { "type" : "text", "boost" : "5.0" },
        "field_tag" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tag:name" : { "type" : "list\\u003Ctext\\u003E" },
        "language" : { "type" : "string" },
        "metatag_abstract" : { "type" : "text" },
        "metatag_alexaVerifyID" : { "type" : "text" },
        "metatag_article:author" : { "type" : "text" },
        "metatag_article:expiration_time" : { "type" : "text" },
        "metatag_article:modified_time" : { "type" : "text" },
        "metatag_article:published_time" : { "type" : "text" },
        "metatag_article:publisher" : { "type" : "text" },
        "metatag_article:section" : { "type" : "text" },
        "metatag_article:tag" : { "type" : "text" },
        "metatag_author" : { "type" : "uri" },
        "metatag_baidu-site-verification" : { "type" : "text" },
        "metatag_book:author" : { "type" : "text" },
        "metatag_book:isbn" : { "type" : "text" },
        "metatag_book:release_date" : { "type" : "text" },
        "metatag_book:tag" : { "type" : "text" },
        "metatag_cache-control" : { "type" : "text" },
        "metatag_canonical" : { "type" : "uri" },
        "metatag_content-language" : { "type" : "text" },
        "metatag_description" : { "type" : "text" },
        "metatag_expires" : { "type" : "text" },
        "metatag_generator" : { "type" : "text" },
        "metatag_geo.placename" : { "type" : "text" },
        "metatag_geo.position" : { "type" : "text" },
        "metatag_geo.region" : { "type" : "text" },
        "metatag_google-site-verification" : { "type" : "text" },
        "metatag_icbm" : { "type" : "text" },
        "metatag_image_src" : { "type" : "uri" },
        "metatag_keywords" : { "type" : "text" },
        "metatag_msvalidate.01" : { "type" : "text" },
        "metatag_news_keywords" : { "type" : "text" },
        "metatag_next" : { "type" : "uri" },
        "metatag_norton-safeweb-site-verification" : { "type" : "text" },
        "metatag_og:audio" : { "type" : "text" },
        "metatag_og:audio:secure_url" : { "type" : "text" },
        "metatag_og:audio:type" : { "type" : "text" },
        "metatag_og:country_name" : { "type" : "text" },
        "metatag_og:description" : { "type" : "text" },
        "metatag_og:determiner" : { "type" : "text" },
        "metatag_og:email" : { "type" : "text" },
        "metatag_og:fax_number" : { "type" : "text" },
        "metatag_og:image" : { "type" : "text" },
        "metatag_og:image:height" : { "type" : "text" },
        "metatag_og:image:secure_url" : { "type" : "text" },
        "metatag_og:image:type" : { "type" : "text" },
        "metatag_og:image:url" : { "type" : "text" },
        "metatag_og:image:width" : { "type" : "text" },
        "metatag_og:latitude" : { "type" : "text" },
        "metatag_og:locale" : { "type" : "text" },
        "metatag_og:locale:alternate" : { "type" : "text" },
        "metatag_og:locality" : { "type" : "text" },
        "metatag_og:longitude" : { "type" : "text" },
        "metatag_og:phone_number" : { "type" : "text" },
        "metatag_og:postal_code" : { "type" : "text" },
        "metatag_og:region" : { "type" : "text" },
        "metatag_og:see_also" : { "type" : "text" },
        "metatag_og:site_name" : { "type" : "text" },
        "metatag_og:street_address" : { "type" : "text" },
        "metatag_og:title" : { "type" : "text" },
        "metatag_og:type" : { "type" : "text" },
        "metatag_og:updated_time" : { "type" : "text" },
        "metatag_og:url" : { "type" : "text" },
        "metatag_og:video:height" : { "type" : "text" },
        "metatag_og:video:secure_url" : { "type" : "text" },
        "metatag_og:video:type" : { "type" : "text" },
        "metatag_og:video:url" : { "type" : "text" },
        "metatag_og:video:width" : { "type" : "text" },
        "metatag_original-source" : { "type" : "text" },
        "metatag_p:domain_verify" : { "type" : "text" },
        "metatag_pragma" : { "type" : "text" },
        "metatag_prev" : { "type" : "uri" },
        "metatag_profile:first_name" : { "type" : "text" },
        "metatag_profile:gender" : { "type" : "text" },
        "metatag_profile:last_name" : { "type" : "text" },
        "metatag_profile:username" : { "type" : "text" },
        "metatag_publisher" : { "type" : "uri" },
        "metatag_rating" : { "type" : "text" },
        "metatag_referrer" : { "type" : "text" },
        "metatag_refresh" : { "type" : "text" },
        "metatag_revisit-after" : { "type" : "text" },
        "metatag_rights" : { "type" : "text" },
        "metatag_robots" : { "type" : "text" },
        "metatag_shortlink" : { "type" : "uri" },
        "metatag_standout" : { "type" : "text" },
        "metatag_title" : { "type" : "text" },
        "metatag_video:actor" : { "type" : "text" },
        "metatag_video:actor:role" : { "type" : "text" },
        "metatag_video:director" : { "type" : "text" },
        "metatag_video:duration" : { "type" : "text" },
        "metatag_video:release_date" : { "type" : "text" },
        "metatag_video:series" : { "type" : "text" },
        "metatag_video:tag" : { "type" : "text" },
        "metatag_video:writer" : { "type" : "text" },
        "metatag_y_key" : { "type" : "text" },
        "metatag_yandex-verification" : { "type" : "text" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_aggregation_1" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "search_api_multi_aggregation_1" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_panelizer_content" : { "type" : "text" },
        "search_api_panelizer_title" : { "type" : "text", "boost" : "5.0" },
        "search_api_url" : { "type" : "uri" },
        "search_api_viewed" : { "type" : "text" },
        "source" : { "type" : "integer", "entity_type" : "node" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "13.0" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "cm_article" : "cm_article",
              "cm_event" : "cm_event",
              "cm_movie" : "cm_movie",
              "cm_movie_group" : "cm_movie_group",
              "cm_person" : "cm_person"
            }
          }
        },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "-49", "settings" : [] },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "-48", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "-47", "settings" : { "mode" : "full" } },
        "panelizer" : { "status" : 1, "weight" : "-46", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "-45", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "-44",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "terms",
                "type" : "list",
                "fields" : [
                  "field_featured_categories",
                  "field_lobby",
                  "field_cm_moviegroup_tags",
                  "field_cm_article_tags",
                  "field_cm_movie_genre",
                  "field_cm_movie_tags",
                  "field_cm_person_type",
                  "field_cm_person_tags",
                  "field_cm_event_category",
                  "field_tag"
                ],
                "description" : "A List aggregation of the following fields: Categories, Lobby, Tags, Tags, Genre, Tags, Profession, Tags, Category, Tag."
              }
            }
          }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-43", "settings" : { "fields" : [] } },
        "search_api_metatag_alter_callback" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_multi_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_multi_aggregation_1" : {
                "name" : "multi term strings",
                "fields" : [
                  "field_cm_moviegroup_tags:name",
                  "field_cm_article_tags:name",
                  "field_cm_movie_tags:name",
                  "field_cm_person_tags:name",
                  "field_tag:name"
                ],
                "description" : "A text aggregation of the following fields: Tags \\u00bb Name, Tags \\u00bb Name, Tags \\u00bb Name, Tags \\u00bb Name, Tag \\u00bb Name."
              }
            }
          }
        },
        "search_api_alter_node_domain_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "search_api_panelizer_content" : true,
              "search_api_panelizer_title" : true,
              "search_api_viewed" : true,
              "body:value" : true,
              "body:summary" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "search_api_panelizer_content" : true,
              "search_api_panelizer_title" : true,
              "search_api_viewed" : true,
              "body:value" : true,
              "body:summary" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : { "status" : 0, "weight" : "15", "settings" : { "fields" : [] } },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "search_api_panelizer_content" : true,
              "search_api_panelizer_title" : true,
              "search_api_viewed" : true,
              "body:value" : true,
              "body:summary" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['node_index'] = entity_import('search_api_index', '{
    "name" : "Solr Node Index",
    "machine_name" : "node_index",
    "description" : null,
    "server" : null,
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "20",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "created" : { "type" : "date" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "search_api_panelizer_content" : { "type" : "text" },
        "search_api_panelizer_title" : { "type" : "text", "boost" : "8.0" },
        "search_api_url" : { "type" : "uri" },
        "search_api_viewed" : { "type" : "text" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "8.0" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-50",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "-49", "settings" : [] },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "-48", "settings" : [] },
        "search_api_alter_add_viewed_entity" : {
          "status" : 1,
          "weight" : "-47",
          "settings" : { "mode" : "search_index" }
        },
        "panelizer" : { "status" : 1, "weight" : "-46", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "-45", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-44", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-43", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "search_api_panelizer_content" : true,
              "search_api_panelizer_title" : true,
              "search_api_viewed" : true,
              "body:value" : true,
              "body:summary" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "search_api_panelizer_content" : true,
              "search_api_panelizer_title" : true,
              "search_api_viewed" : true,
              "body:value" : true,
              "body:summary" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "title" : true,
              "search_api_viewed" : true,
              "body:value" : true,
              "body:summary" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "search_api_panelizer_content" : true,
              "search_api_panelizer_title" : true,
              "search_api_viewed" : true,
              "body:value" : true,
              "body:summary" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\\u0027]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "0",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function panopoly_search_default_search_api_server() {
  $items = array();
  $items['database_server'] = entity_import('search_api_server', '{
    "name" : "Database Server",
    "machine_name" : "database_server",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "partial_matches" : 0,
      "indexes" : { "database_node_index" : {
          "nid" : {
            "table" : "search_api_db_database_node_index",
            "column" : "nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_database_node_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "13.0"
          },
          "url" : {
            "table" : "search_api_db_database_node_index",
            "column" : "url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_database_node_index",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_database_node_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_database_node_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_database_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_url" : {
            "table" : "search_api_db_database_node_index",
            "column" : "search_api_url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "search_api_viewed" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_database_node_index_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "body:summary" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_panelizer_content" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_panelizer_title" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "field_cm_article_tags" : {
            "table" : "search_api_db_database_node_index_field_cm_article_tags",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_cm_movie_year" : {
            "table" : "search_api_db_database_node_index",
            "column" : "field_cm_movie_year",
            "type" : "integer",
            "boost" : "1.0"
          },
          "language" : {
            "table" : "search_api_db_database_node_index",
            "column" : "language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_cm_movie_country" : {
            "table" : "search_api_db_database_node_index_field_cm_movie_country",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "source" : {
            "table" : "search_api_db_database_node_index",
            "column" : "source",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_cm_movie_language" : {
            "table" : "search_api_db_database_node_index_field_cm_movie_language",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_cm_movie_subtitle" : {
            "table" : "search_api_db_database_node_index_field_cm_movie_subtitle",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_cm_movie_credits" : {
            "table" : "search_api_db_database_node_index_field_cm_movie_credits",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_cm_movie_internal_id" : {
            "table" : "search_api_db_database_node_index",
            "column" : "field_cm_movie_internal_id",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_cm_movie_genre" : {
            "table" : "search_api_db_database_node_index_field_cm_movie_genre",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_cm_movie_alt_title" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_cm_movie_tags" : {
            "table" : "search_api_db_database_node_index_field_cm_movie_tags",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_lobby" : {
            "table" : "search_api_db_database_node_index_field_lobby",
            "column" : "field_lobby",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_mc_teaser_toptxt_blk" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "0.8"
          },
          "field_mc_teaser_toptxt_white" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "0.8"
          },
          "field_cm_movie_meta_credit" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "2.0"
          },
          "field_cm_moviegroup_tags" : {
            "table" : "search_api_db_database_node_index_field_cm_moviegroup_tags",
            "column" : "field_cm_moviegroup_tags",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_movie_group_top_text_black" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_movie_group_top_text_white" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_cm_event_short_title" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "field_cm_event_subtitle" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "2.0"
          },
          "field_cm_event_comment" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_cm_event_hall" : {
            "table" : "search_api_db_database_node_index",
            "column" : "field_cm_event_hall",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_tag" : {
            "table" : "search_api_db_database_node_index_field_tag",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_main_event_credit" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_article_top_text_white" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_article_top_text_black" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_cm_person_tags" : {
            "table" : "search_api_db_database_node_index_field_cm_person_tags",
            "column" : "field_cm_person_tags",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_cm_article_subtitle" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "2.0"
          },
          "field_search_additions" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "field_cm_person_first_name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_cm_person_last_name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_cm_person_job_title" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "domain_domain_id" : {
            "table" : "search_api_db_database_node_index_domain_domain_id",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "domain_subdomain" : {
            "table" : "search_api_db_database_node_index_domain_subdomain",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "domain_sitename" : {
            "table" : "search_api_db_database_node_index_domain_sitename",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "metatag_title" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_description" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_abstract" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_keywords" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_robots" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_news_keywords" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_standout" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_rating" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_referrer" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_generator" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_rights" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_image_src" : {
            "table" : "search_api_db_database_node_index",
            "column" : "metatag_image_src",
            "type" : "uri",
            "boost" : "1.0"
          },
          "metatag_canonical" : {
            "table" : "search_api_db_database_node_index",
            "column" : "metatag_canonical",
            "type" : "uri",
            "boost" : "1.0"
          },
          "metatag_shortlink" : {
            "table" : "search_api_db_database_node_index",
            "column" : "metatag_shortlink",
            "type" : "uri",
            "boost" : "1.0"
          },
          "metatag_publisher" : {
            "table" : "search_api_db_database_node_index",
            "column" : "metatag_publisher",
            "type" : "uri",
            "boost" : "1.0"
          },
          "metatag_author" : {
            "table" : "search_api_db_database_node_index",
            "column" : "metatag_author",
            "type" : "uri",
            "boost" : "1.0"
          },
          "metatag_original-source" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_prev" : {
            "table" : "search_api_db_database_node_index",
            "column" : "metatag_prev",
            "type" : "uri",
            "boost" : "1.0"
          },
          "metatag_next" : {
            "table" : "search_api_db_database_node_index",
            "column" : "metatag_next",
            "type" : "uri",
            "boost" : "1.0"
          },
          "metatag_content-language" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_geo.position" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_geo.placename" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_geo.region" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_icbm" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_refresh" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_revisit-after" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_pragma" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_cache-control" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_expires" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:site_name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:type" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:url" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:title" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:determiner" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:description" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:updated_time" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:see_also" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:image" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:image:url" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:image:secure_url" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:image:type" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:image:width" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:image:height" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:latitude" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:longitude" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:street_address" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:locality" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:region" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:postal_code" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:country_name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:email" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:phone_number" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:fax_number" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:locale" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:locale:alternate" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_article:author" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_article:publisher" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_article:section" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_article:tag" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_article:published_time" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_article:modified_time" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_article:expiration_time" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_profile:first_name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_profile:last_name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_profile:username" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_profile:gender" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:audio" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:audio:secure_url" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:audio:type" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_book:author" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_book:isbn" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_book:release_date" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_book:tag" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:video:url" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:video:secure_url" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:video:width" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:video:height" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_og:video:type" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_video:actor" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_video:actor:role" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_video:director" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_video:writer" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_video:duration" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_video:release_date" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_video:tag" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_video:series" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_alexaVerifyID" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_msvalidate.01" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_baidu-site-verification" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_google-site-verification" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_norton-safeweb-site-verification" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_p:domain_verify" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_y_key" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "metatag_yandex-verification" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_aggregation_1" : {
            "table" : "search_api_db_database_node_index_search_api_aggregation_1",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "search_api_multi_aggregation_1" : {
            "table" : "search_api_db_database_node_index_search_api_multi_aggregation",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0",
            "column" : "value"
          },
          "field_lobby:name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_cm_moviegroup_tags:name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_cm_article_tags:name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_cm_movie_tags:name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_cm_person_type:name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_cm_person_tags:name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_cm_event_hall:name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_tag:name" : {
            "table" : "search_api_db_database_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  $items['solr_server'] = entity_import('search_api_server', '{
    "name" : "Solr Server",
    "machine_name" : "solr_server",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 1,
      "retrieve_data" : 0,
      "highlight_data" : 0
    },
    "enabled" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
